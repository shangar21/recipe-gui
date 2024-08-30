# Recipe-CLI

Recipe-CLI is a Qt-based desktop application that allows users to create, manage, and view recipes. It also provides functionality to generate a grocery list by aggregating ingredients from selected recipes, making meal planning and shopping easier and more organized.

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
- **range-v3**: Can be built from source from [range-v3 repo](https://github.com/ericniebler/range-v3), or from `externals/range-v3` in this repo

### Steps

1. **Clone the Repository**:

    ```bash
    git clone git@github.com:shangar21/recipe-cli.git
    cd recipe-cli
    git submodule update --init --recursive
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

