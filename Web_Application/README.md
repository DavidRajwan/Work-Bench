# Learning Log Web Application

This project showcases the creation of a simple web application using the Django framework. The web application, called Learning Log, allows users to create an account and record their learning progress. Users can add new topics and create entries to summarize what they have learned about each topic.

## Project Overview

The Learning Log web application offers the following features:

- User Authentication: Users can create an account, log in, and log out.
- Topic Management: Users can add new topics and view the topics they have created.
- Entry Creation: Users can create entries to record what they have learned about each topic.
- Entry Viewing: Users can view and edit the entries associated with each topic.

## Getting Started

To get started with the Learning Log web application, please follow these steps:

1. Clone or download this repository to your local machine.
2. Open a terminal or command prompt.
3. Create a virtual environment using Python's built-in `venv` module:
    ```shell
    python -m venv myenv
    ```
4. Activate the virtual environment:
    - On Windows:
        ```shell
        myenv\Scripts\activate
        ```
    - On macOS and Linux:
        ```shell
        source myenv/bin/activate

5. Download the project's dependencies by running the following command:

   ```
   pip install -r requirements.txt
   ```

   This command will install the necessary dependencies for the project.

6. Start the Django project by running the following command:

   ```
   python manage.py runserver
   ```

   This command will launch the development server, and you can access the web application by visiting the provided URL.

7. Explore the Learning Log web application in your web browser. Create an account, add topics, and create entries to track your learning progress.

## Project Structure

The project is structured as follows:

- `learning_log/`: The main project directory.
  - `learning_log/`: Contains the Django project settings.
  - `learning_logs/`: The Django app directory for the learning log functionality.
  - `users/`: The Django app directory for the users functionality. 
    - `migrations/`: Database migration files.
    - `templates/`: HTML templates for rendering the web pages.
    - `models.py`: Defines the database models for topics and entries.
    - `views.py`: Contains the views for handling user requests and rendering templates.
  - `manage.py`: The Django management script for running the project.

## Credits

This project drew inspiration and knowledge from the following resources:

- Django Official Documentation: [https://docs.djangoproject.com/](https://docs.djangoproject.com/)
- Python Crash Course, 2nd Edition: A Hands-On, Project-Based Introduction to Programming by Eric Matthes

## Contributing

If you would like to contribute to the Learning Log web application, please feel free to submit a pull request or open an issue on the project's repository.

Happy learning with Learning Log!