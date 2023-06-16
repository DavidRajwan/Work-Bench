import sys
from time import sleep
from random import sample

import pygame

from settings import Settings
from game_stats import GameStats
from scoreboard import Scoreboard
from button import Button
from level_button import LevelButton
from ship import Ship
from pulsor import Pulsor
from alien import Alien
from star import Star



class AlienInvasion:
    """Overall class to manage game assets and behaviors."""

    def __init__(self):
        """Initialize the game, and crate game resources."""
        pygame.init()
        self.settings = Settings()
        self.clock = pygame.time.Clock()

        """Numeric Screen Mode"""
        self.screen = pygame.display.set_mode((
            self.settings.screen_width, self.settings.screen_height))
        
        """Full Screen Mode"""
        #self.screen = pygame.display.set_mode((0, 0), pygame.FULLSCREEN)
        #self.settings.screen_width = self.screen.get_rect().width
        #self.settings.screen_height = self.screen.get_rect().height

        pygame.display.set_caption("Alien Invasion")

        # Create an instance to store game statistics.
        self.stats = GameStats(self)
        # Create a scoreboard
        self.sb = Scoreboard(self)

        self.ship = Ship(self)
        self.pulsors = pygame.sprite.Group()
        self.aliens = pygame.sprite.Group()
        self.stars = []

        self._create_stars()
        self._create_fleet()

        # Make the play button
        self.play_button = Button(self, "Play")

        # Make Level Buttons
        self.easy_button = LevelButton(self, "Easy", 60)
        self.medium_button = LevelButton(self, "Medium", 120)
        self.hard_button = LevelButton(self, "Hard", 180)

        
    # ----------------------------- MAIN GAME LOOP -------------------------------------

    def run_game(self):
        """Start the main loop for the game."""
        while True:
            # Watch for keyboard and mosue events.
            self._check_events()

            if self.stats.game_active:
                # Update ship movement
                self.ship.update()

                # Update pulsors
                self._update_pulsors()

                # Update aliens
                self._update_aliens()

            # Redraw and update most recent drawn screen
            self._update_screen()    

    # ----------------------------- PLAYER CONTROLS -------------------------------------

    def _check_events(self):
        """ Respond to keypress and mouse events"""
        for event in pygame.event.get():

            if event.type == pygame.QUIT:
                sys.exit()

            elif event.type == pygame.KEYDOWN:
                self._check_keydown_events(event)

            elif event.type == pygame.KEYUP:
                self._check_keyup_events(event)
            
            elif event.type == pygame.MOUSEBUTTONDOWN:
                mouse_pos = pygame.mouse.get_pos()
                self._check_play_button(mouse_pos)
                self._check_level_button(mouse_pos)
    
    def _check_play_button(self, mouse_pos):
        """Start a new game when the player clicks Play."""
        button_clicked = self.play_button.rect.collidepoint(mouse_pos)
        if button_clicked and not self.stats.game_active:
            # Reset the game settings.
            self.settings.initialize_dynamic_settings()
            self._start_game()
            
    
    def _check_level_button(self, mouse_pos):
        """Start a new game when the player clicks Play."""
        easy_clicked = self.easy_button.rect.collidepoint(mouse_pos)
        medium_clicked = self.medium_button.rect.collidepoint(mouse_pos)
        hard_clicked = self.hard_button.rect.collidepoint(mouse_pos)
        if easy_clicked and not self.stats.game_active:
            # Reset the game settings.
            self.settings.initialize_dynamic_settings()
            self.settings.speedup_scale = 1.1
            self.settings.score_scale = 1.1
            self._start_game()
        elif medium_clicked and not self.stats.game_active:
            # Reset the game settings.
            self.settings.initialize_dynamic_settings()
            self.settings.speedup_scale = 1.25
            self.settings.score_scale = 1.25
            self._start_game()
        elif hard_clicked and not self.stats.game_active:
            # Reset the game settings.
            self.settings.initialize_dynamic_settings()
            self.settings.speedup_scale = 1.5
            self.settings.score_scale = 1.75
            self._start_game()
            
            
    def _check_keydown_events(self, event):
        """Respond to keypresses."""
        if event.key == pygame.K_RIGHT:
            #Move the ship to the right.
            self.ship.moving_right = True
        elif event.key == pygame.K_LEFT:
            #Move the ship to the left.
            self.ship.moving_left = True
        elif event.key == pygame.K_q:
            sys.exit()
        elif event.key == pygame.K_SPACE:
            self._fire_pulsors()
        elif event.key == pygame.K_p:
            self.settings.initialize_dynamic_settings()
            self._start_game()
            
    def _check_keyup_events(self, event):
        """Respond to key releases."""
        if event.key == pygame.K_RIGHT:
            self.ship.moving_right = False
        elif event.key == pygame.K_LEFT:
            self.ship.moving_left = False
    
    def _start_game(self):
        """Restart the game"""
        # Reset the game statistics.
        self.stats.reset_stats()
        self.sb.prep_score()
        self.sb.prep_level()
        self.sb.prep_ships()
        self.stats.game_active = True

        # Get rid of any remaining aliens and pulsors.
        self.aliens.empty()
        self.pulsors.empty()

        # Create a new fleet and center the ship. 
        self._create_fleet()
        self.ship.center_ship()

        # Hide the mouse cursor.
        pygame.mouse.set_visible(False)

    # ----------------------------- PULSOR FUNCTIONS -----------------------------------------

    def _fire_pulsors(self):
        """Create a new pulsor and add it to the pulsors group."""
        if len(self.pulsors) < self.settings.pulsors_allowed:
            new_pulsor = Pulsor(self)
            self.pulsors.add(new_pulsor)

    def _update_pulsors(self):
        """Update position of pulsors and get rid of old pulsors."""
        # Update pulsor postions.
        self.pulsors.update()

        # Get rid of the pulsors that have disappeared.
        for pulsor in self.pulsors.copy():
            if pulsor.rect.bottom <= 0:
                self.pulsors.remove(pulsor)
        #print(len(self.pulsors))

        self._check_pulsor_alien_collisions()

    # ----------------------------- COLLISION DETECTIONS -------------------------------------    

    def _check_pulsor_alien_collisions(self):
        """Respond to pulsor-alien collisions."""
        # Remove any bullets and aliens that have collided.

        # Check for any pulsor that have hit aliens.
        #   If so, get rid of the pulsor and the alien
        collisions = pygame.sprite.groupcollide(
            self.pulsors, self.aliens, True, True)

        if collisions:
            for aliens in collisions.values():
                self.stats.score += self.settings.alien_points * len(aliens)
            self.sb.prep_score() 
            self.sb.check_high_score()

        if not self.aliens:
            # Destroy existing pulsors and create a new fleet.
            self.pulsors.empty()
            self._create_fleet()
            self.settings.increase_speed()

             # Increase level.
            self.stats.level += 1
            self.sb.prep_level()

    def _ship_hit(self):
        """Respond to the ship being hit by an alien."""
        if self.stats.ships_left > 0:
            # Decrement ships_left, explode ship, and update scoreboard
            self.ship.explode()
            self._update_screen()
            self.stats.ships_left -= 1
            self.sb.prep_ships()

            # Get rid of any remaining aliens and bullets.
            self.aliens.empty()
            self.pulsors.empty()
            
            # Create a new fleet and center the ship.
            self._create_fleet()
            self.ship.center_ship()

            # Pause
            sleep(1)
        else:
            self.stats.game_active = False
            pygame.mouse.set_visible(True)

    # ----------------------------- ALIEN FUNCTIONS -------------------------------------

    def _update_aliens(self):
        """
        Check if the fleet is at an edge,
            then update the positions of all aliens in the fleet.
        """
        self._check_fleet_edges()
        self.aliens.update()

        # Look for alien-ship collisons.
        if pygame.sprite.spritecollideany(self.ship, self.aliens):
            self._ship_hit()
        
        # Look for aliens hitting the bottom of the screen.
        self._check_aliens_bottom()

    def _check_aliens_bottom(self):
        """Check if any aliens have reached the bottom of the screen."""
        screen_rect = self.screen.get_rect()
        for alien in self.aliens.sprites():
            if alien.rect.bottom >= screen_rect.bottom:
                # Treat this the same as if ship got hit.
                self._ship_hit()
                break

    def _create_fleet(self):
        """Create the fleet of aliens."""
        # Make an alien and find the number of aliens in a row.
        # Spacing between each alien is equal to one alien width.
        alien = Alien(self)
        alien_width, alien_height = alien.rect.size
        available_space_x = self.settings.screen_width - (2 * alien_width)
        number_aliens_x = available_space_x // (2 * alien_width)

        # Determine the number of rows of aliens that fit on the screen.
        ship_height = self.ship.rect.height
        available_space_y = (self.settings.screen_height - 
                             (3 * alien_height) - ship_height)
        number_rows = available_space_y // (2 * alien_height)

        # Create the full fleet of aliens
        for row_number in range(number_rows):
            # Create the row of aliens.
            for alien_number in range(number_aliens_x):
                # Create an alien and place it in the row.
                self._create_alien(alien_number, row_number)
        
    def _create_alien(self, alien_number, row_number):
        """Create an alien and place it in the row."""
        alien = Alien(self)
        alien_width, alien_height = alien.rect.size
        alien.x = alien_width + 2 * alien_width * alien_number
        alien.rect.x = alien.x
        alien.rect.y = alien.rect.height + 2 * alien_height * row_number
        self.aliens.add(alien)

    def _check_fleet_edges(self):
        """Respond appropriately if the any aliens have reached an edge."""
        for alien in self.aliens.sprites():
            if alien.check_edges():
                self._change_fleet_direction()
                break
    
    def _change_fleet_direction(self):
        """Drop the entire fleet and change the fleet's direction."""
        for alien in self.aliens.sprites():
            alien.rect.y += self.settings.fleet_drop_speed
        self.settings.fleet_direction *= -1

    # ----------------------------- STAR FUNCTIONS -------------------------------------

    def _create_stars(self):
        """Create the random stars."""
        for star_number in range(self.settings.number_of_stars):
            # Create an alien and place it in the row.
            self._create_star()
    
    def _create_star(self):
        """Create an alien and place it in the row."""
        star = Star(self)
        self.stars.append(star)
    
    def _pick_random_stars(self):
        random_indices = sample(range(0, self.settings.stars_changing), 5)
        for index in (random_indices):
            self.stars[index].start_moving()

    def _update_stars(self):
        """Update star location"""
        self._pick_random_stars()

        for star in self.stars:
            if star.moving:
                star.update()
            star.draw()
    
    # ----------------------------- SCREEN FUNCTIONS -------------------------------------
        
    def _update_screen(self):
        """Update images on the screen, and flip to the new screen."""
        # Redraw the screen during each pass through the loop.
        self.screen.fill(self.settings.bg_color)
        self._update_stars()
        self.ship.blitme()

        # Show pulsors
        for pulsor in self.pulsors.sprites():
            pulsor.draw_pulsor()
        
        self.aliens.draw(self.screen)

        # Draw the score information.
        self.sb.show_score()

        # Draw the buttons if the game is inactive
        if not self.stats.game_active:
            self.play_button.draw_button()
            self.easy_button.draw_button()
            self.medium_button.draw_button()
            self.hard_button.draw_button()
    
        # Make the most recently drawn screen visible.
        pygame.display.flip()
        #self.clock.tick(720)

if __name__=='__main__':
    # Make a game instance, and run the game.
    ai = AlienInvasion()
    ai.run_game()