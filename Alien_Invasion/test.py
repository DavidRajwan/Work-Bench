from alien_invasion import AlienInvasion

class TestAlienInvasion():
    """Tests for the class AlienInvasion"""

    def __init__(self):
        """
        Create an AlienInvasion Games and set up the settings for 
        each specific game for specific test scenarios
        """
        
        self.fleet_reset_game = AlienInvasion()
        self.fleet_reset_game.settings.pulsor_width = 3000 
        
    
    def test_fleet_reset(self):
        """Test whether the alien fleet resets once all the units are shot down"""
        self.fleet_reset_game.run_game()

if __name__ == '__main__':
    tester = TestAlienInvasion()
    tester.test_fleet_reset()
        