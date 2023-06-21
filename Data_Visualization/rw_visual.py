import matplotlib.pyplot as plt

from random_walk import RandomWalk


def _keep_running():
    """Function to determine if the user wants to keep making new walks"""
    keep_running = input("Make another walk? (y/n): ")
    if keep_running == 'n' or keep_running == 'N':
        return 0
    elif keep_running == 'y' or keep_running == 'Y':
        return 1
    else:
        return _keep_running()

# Keep making new walks, as long as the program is active.
while True:

    # Make a random walk.
    rw = RandomWalk(50_000)
    rw.fill_walk()

    # Plot the points in the walk.
    plt.style.use('classic')
    fig, ax = plt.subplots(figsize=(9, 5), dpi=128)
    point_numbers = range(rw.num_points)
    ax.scatter(rw.x_values, rw.y_values, c=point_numbers, cmap=plt.cm.Blues, edgecolors='none', s=1)

    # Emphasize the first and last points.
    ax.scatter(0, 0, c='green', edgecolors='none', s=100)
    ax.scatter(rw.x_values[-1], rw.y_values[-1], c='red', edgecolors='none', s=100)

    # Remove the axes.
    ax.get_xaxis().set_visible(False)
    ax.get_yaxis().set_visible(False)

    plt.savefig('Graphs/random_walk.png', bbox_inches='tight')
    plt.show()

    running = _keep_running()
    if running == 1:
        continue
    else:
        break