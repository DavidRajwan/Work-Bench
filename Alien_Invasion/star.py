import pygame
from random import randint
import time
from pygame.sprite import Sprite

class Star(Sprite):
    """A class to manage the ship."""

    def __init__(self, ai_game):
        """Initialize the star and set its starting position"""
        super().__init__()
        self.screen = ai_game.screen
        self.settings = ai_game.settings
        self.screen_rect = ai_game.screen.get_rect()

        # Load the star image and get its rect. 
        self.image = pygame.image.load('images/star.bmp')
        self.rect = self.image.get_rect()

        #Start each new star near the top of the left screen.
        self.rect.x = randint(0, self.settings.screen_width)
        self.rect.y = randint(0, self.settings.screen_height)
        self.timer = time.time() + 2  # Set the initial timer for 2 seconds

        #Stars movement flag
        self.moving = False

    def update(self):
        if time.time() >= self.timer:  # If the timer expires
            self.rect.x = randint(0, self.settings.screen_width)  # Move to a new random location
            self.rect.y = randint(0, self.settings.screen_height)
            self.timer = time.time() + 2  # Reset the timer for 2 seconds
            self.moving = False

    def start_moving(self):
        self.moving = True
        
    def draw(self):
        self.screen.blit(self.image, self.rect)