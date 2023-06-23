from plotly.graph_objs import Bar, Layout
from plotly import offline 

from die import Die

# ----------------------------- ONE DICE -----------------------------

def roll_one_dice(sides1, rolls):
    """Roll one six-sided dice"""

    # Create a D6 dice.
    die = Die(sides1)

    # Make some rolls, and store results in a list.
    results = []
    for roll_num in range(rolls):
        result = die.roll()
        results.append(result)

    # Analyze the results.
    frequencies = []
    for value in range(1, (die.num_sides+1)):
        frequency = results.count(value)
        frequencies.append(frequency)

    # Visualize the results.
    x_values = list(range(1, (die.num_sides+1)))
    data = [Bar(x=x_values, y=frequencies)]

    x_axis_config = {'title': 'Result'}
    y_axis_config = {'title': 'Frequencies of Result'}
    my_layout = Layout(title=f'Result of rolling one D{sides1} {rolls} times', xaxis=x_axis_config, yaxis=y_axis_config)
    offline.plot({'data': data, 'layout': my_layout}, filename='d6.html')


# ----------------------------- TWO DICE -----------------------------

def roll_two_dice(sides1, sides2, rolls):
    """Roll two six-sided dice"""

    # Create two D6 dice.
    die_1 = Die(sides1)
    die_2 = Die(sides2)

    # Make some rolls, and store results in a list.
    results = []
    for roll_num in range(rolls):
        result = die_1.roll() + die_2.roll()
        results.append(result)

    # Analyze the results.
    frequencies = []
    max_result = die_1.num_sides + die_2.num_sides
    for value in range(2, (max_result+1)):
        frequency = results.count(value)
        frequencies.append(frequency)

    # Visualize the results.
    x_values = list(range(2, (max_result+1)))
    data = [Bar(x=x_values, y=frequencies)]

    x_axis_config = {'title': 'Result', 'dtick': 1}
    y_axis_config = {'title': 'Frequencies of Result'}
    my_layout = Layout(title=f'Result of rolling a D{sides1} and a D{sides2} {rolls} times', xaxis=x_axis_config, yaxis=y_axis_config)
    offline.plot({'data': data, 'layout': my_layout}, filename=f'd{sides1}_d{sides2}.html')

if __name__=='__main__':
    # Make a game instance, and run the game.
    roll_one_dice(5, 1100)
    roll_two_dice(7, 7, 1100)
    roll_two_dice(6, 10, 50_000)