import pygame
from pygame.sprite import Sprite

class Pulsor(Sprite):
    """A class to manage pulsors fired from the ship"""

    def __init__(self, ai_game):
        """Create a pulsor object at the ship's current position."""
        super().__init__()
        self.screen = ai_game.screen
        self.settings = ai_game.settings 
        self.color = self.settings.pulsor_color

        # Create a pulsor rect at (0, 0) and then set correct position.
        self.rect = pygame.Rect(0, 0, self.settings.pulsor_width, self.settings.pulsor_height) 
        self.rect.midtop = ai_game.ship.rect.midtop

        # Store the pulsor's position as a decimal value.
        self.y = float(self.rect.y)

    def update(self):
        """Move the pulsor up the screen."""
        # Update the decimal position of the bullet.
        self.y -= self.settings.pulsor_speed
        # Update the rect position.
        self.rect.y = self.y

    def draw_pulsor(self):
        """Draw the pulsor to the screen."""
        pygame.draw.rect(self.screen, self.color, self.rect)