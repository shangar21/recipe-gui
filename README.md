# Recipe-GUI

Recipe-GUI is a Qt-based desktop application that allows users to create, manage, and view recipes. It also provides functionality to generate a grocery list by aggregating ingredients from selected recipes, making meal planning and shopping easier and more organized.

## Features

- **Add Recipes**: Create new recipes with a name, description, and detailed instructions.
- **Manage Ingredients**: Add existing ingredients from a list or create new ones with specified quantities and units.
- **View Recipes**: Browse and view details of all saved recipes.
- **Generate Grocery List**: Automatically generate a grocery list by selecting multiple recipes. The app aggregates all required ingredients and quantities for easy shopping.

## Installation

### Prerequisites

- **Qt**: Ensure that you have Qt installed on your system. You can download and install Qt from the [official Qt website](https://www.qt.io/download).
- **CMake**: Ensure CMake is installed on your system. You can download it from [CMake's official website](https://cmake.org/download/).
- **sqlite3**: Ensure sqlite3 is installed on system.

### Steps

1. **Clone the Repository**:

    ```bash
    git clone git@github.com:shangar21/recipe-cli.git
    cd recipe-cli
    ```

2. **Build the Project**:

    Use CMake to configure and build the project. Run the following commands in your terminal:

    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

3. **Run the Application**:

    After building the project, run the application using:

    ```bash
    ./recipe_cli
    ```

## Usage

1. **Open the Application**: Launch the application by running the executable.

2. **Add a Recipe**:
   - Enter the recipe name and description in the provided text fields.
   - Enter the instructions for the recipe in the instructions text area.
   - Use the drop-down menu to select an existing ingredient or type a new one.
   - Specify the quantity and unit for each ingredient and click "Add Ingredient."
   - Click the "Save" button to save the recipe.

3. **View Recipes**:
   - Navigate to the "View Recipes" section to browse all saved recipes.
   - Click on any recipe to view its details, including ingredients and instructions.

4. **Generate Grocery List**:
   - Select multiple recipes to include in your grocery list.
   - The application will aggregate all ingredients and quantities needed from the selected recipes.
   - View or print the generated grocery list for easy shopping.
  
## Samples

### Main Menu
![image](https://github.com/user-attachments/assets/5208c95d-c912-4935-ac77-347d567f1385)

### View Recipe Titles (click to see more details)
![image](https://github.com/user-attachments/assets/c7199540-c8ca-41d4-a3f4-4ef78837a0c1)
![image](https://github.com/user-attachments/assets/d4c63b31-7fca-45af-9b03-8ca060d17f6c)


### Add Ingredient Screen
![image](https://github.com/user-attachments/assets/fa25204c-679e-4fa0-a3c2-1115f04334b3)
![image](https://github.com/user-attachments/assets/5d184c29-9244-40ee-80ff-90e97c5b9b96)

### 

## Future Enhancements

- **Recipe Import/Export**: Add functionality to import recipes from files and export existing recipes for sharing.
- **Recipe Search**: Implement search and filter features for quickly finding specific recipes.
- **Nutrition Calculation**: Add nutritional information calculation based on ingredients.

## Contributing

Contributions are welcome! If you would like to contribute to the project, please follow these steps:

1. Fork the repository.
2. Create a new branch: `git checkout -b feature-branch-name`.
3. Make your changes and commit them: `git commit -m 'Add some feature'`.
4. Push to the branch: `git push origin feature-branch-name`.
5. Open a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Contact

For any questions or feedback, please contact [sharanshangar@gmail.com].

