Food Ingredients Checker:-

A C++ OOP Project
This project, Food Ingredients Checker, is designed to provide users with detailed insights into the ingredients of various food items. Built with C++ and leveraging Object-Oriented Programming (OOP) concepts and file handling, it is a practical application for learning and demonstrating the power of C++ programming in a real-world scenario.

The application organizes food items into categories, such as Snacks, Chocolates, Meals, Pickles, and Ice Creams, and allows users to explore their ingredients and assess whether the food is healthy or not.

Features of the Project

1. Organized Food Categories
The program categorizes food items into five main categories:
Snacks
Chocolates
Meals
Pickles
Ice Creams
Each category contains 100 food items with corresponding ingredients and health assessments.

2. Ingredient Details
Provides detailed ingredient lists with percentages for each food item.
Highlights the health status of the food item (Healthy/Unhealthy) based on its composition.

3. User Interaction
The user can:
Select a category by number.
Choose a specific food item within that category.
View details about the selected food item.

4. File Handling for Data Storage
Food data is stored in text files (snacks.txt, chocolates.txt, etc.), which are read by the program to display information dynamically.
This design makes it easy to update or expand the dataset without modifying the core program.

5. Object-Oriented Approach
Classes Used:
FoodItem: Represents a single food item with its name, ingredients, and health status.
FoodCategory: Represents a category of food items and provides methods to manage and display items.

6. Extensibility
The project is designed to be easily extensible:
New categories or food items can be added by updating the respective text files.
Additional features, such as searching by ingredient or filtering by health status, can be implemented.
Technologies and Concepts Used


Programming Language
C++

Key Concepts
Object-Oriented Programming (OOP)
Classes and Objects
Encapsulation and Abstraction
Constructor Initialization
Data Structures
Vectors for dynamic data handling
File Handling
Reading data from text files
Parsing and managing structured data
Standard Template Library (STL)

How It Works

Data Setup

Food data is pre-stored in text files (e.g., snacks.txt, chocolates.txt).
Each file contains the food name, ingredients (with percentages), and a health status.
Program Flow


The program starts by displaying the list of food categories.
The user selects a category and then a specific food item.
The program fetches and displays the ingredients and health status of the selected item.
Example Interaction







User selects Snacks.
The program lists 100 snack options, such as "Lays" or "Doritos."
The user selects "Lays," and the program displays:
Food Name: Lays
Ingredients:
- Potato: 60%
- Salt: 10%
- Oil: 30%
Health Status: Unhealthy
