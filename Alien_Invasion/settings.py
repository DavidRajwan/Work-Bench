class Settings:
    """A class to store all settings for Alien Invasion."""

    def __init__(self):
        """Initialize the game's static settings."""

        # Screen settings
        self.screen_width = 750
        self.screen_height = 350
        self.bg_color = (0, 30, 110)

        # Ship settings
        self.ship_limit = 3

        # Pulsor settings
        self.pulsor_width = 3
        self.pulsor_height = 15
        self.pulsor_color = (0, 255, 0)
        self.pulsors_allowed = 3

        # Alien settings
        self.fleet_drop_speed = 50
        
        # Star settings
        self.number_of_stars = 20
        self.stars_changing = 5

        self.initialize_dynamic_settings()

    
    def initialize_dynamic_settings(self):
        """Initialize settings that change throughout the game."""
        self.ship_speed = 0.5
        self.pulsor_speed = 1.0
        self.alien_speed = 0.1

        # How quickly the game speeds up
        self.speedup_scale = 1.01

        # fleet_direction of 1 represents right; -1 represents left.
        self.fleet_direction = 1

        # How quickly the alien point values increase
        self.score_scale = 1.5

        # Scoring
        self.alien_points = 50

    def increase_speed(self):
        """Increase speed settings and alien point values."""
        self.ship_speed *= self.speedup_scale
        self.pulsor_speed *= self.speedup_scale
        self.alien_speed *= self.speedup_scale

        self.alien_points = int(self.alien_points * self.score_scale)
    
        