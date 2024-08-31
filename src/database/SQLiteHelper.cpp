#include "SQLiteHelper.h"

SQLiteHelper::SQLiteHelper(const std::string &db_path) {
  if (sqlite3_open(db_path.c_str(), &db_) != SQLITE_OK) {
    std::cerr << "Error opening database: " << db_path
              << " Error: " << sqlite3_errmsg(db_) << std::endl;
    db_ = nullptr;
  }
}

SQLiteHelper::~SQLiteHelper() {
  if (db_) {
    sqlite3_close(db_);
  }
}

bool SQLiteHelper::executeQuery(const std::string &query) {
  char *errorMsg;
  int result = sqlite3_exec(db_, query.c_str(), nullptr, nullptr, &errorMsg);
  if (result != SQLITE_OK) {
    std::cerr << "SQL error: " << errorMsg << std::endl;
    sqlite3_free(errorMsg);
    return false;
  }
  return true;
}

bool SQLiteHelper::executeParameterizedQuery(const std::string &query,
                                             const std::string &param) {
  sqlite3_stmt *stmt;
  const char *tail;

  // Prepare the SQL statement
  if (sqlite3_prepare_v2(db_, query.c_str(), -1, &stmt, &tail) != SQLITE_OK) {
    std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db_)
              << std::endl;
    return false;
  }

  // Bind the parameter to the statement (index 1 since SQLite uses 1-based
  // indexing)
  if (sqlite3_bind_text(stmt, 1, param.c_str(), -1, SQLITE_TRANSIENT) !=
      SQLITE_OK) {
    std::cerr << "Failed to bind parameter: " << sqlite3_errmsg(db_)
              << std::endl;
    sqlite3_finalize(stmt);
    return false;
  }

  // Execute the statement
  if (sqlite3_step(stmt) != SQLITE_DONE) {
    std::cerr << "Failed to execute statement: " << sqlite3_errmsg(db_)
              << std::endl;
    sqlite3_finalize(stmt);
    return false;
  }

  // Finalize the statement to clean up
  sqlite3_finalize(stmt);
  return true;
}

std::vector<Recipe> SQLiteHelper::fetchRecipes() {
  std::vector<Recipe> recipes;
  sqlite3_stmt *stmt;
  std::string query =
      "SELECT id, title, description, instructions FROM recipes;";

  // Prepare the SQL statement
  if (sqlite3_prepare_v2(db_, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
    // Execute and fetch each row
    while (sqlite3_step(stmt) == SQLITE_ROW) {
      Recipe recipe;
      recipe.id = sqlite3_column_int(stmt, 0);
      recipe.title = QString::fromUtf8(
          reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
      recipe.description = QString::fromUtf8(
          reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
      recipe.instructions = QString::fromUtf8(
          reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)));
      recipes.push_back(recipe);
    }
  } else {
    std::cerr << "Failed to fetch recipes: " << sqlite3_errmsg(db_)
              << std::endl;
  }

  // Finalize the statement to release resources
  sqlite3_finalize(stmt);
  return recipes;
}

std::vector<Ingredient> SQLiteHelper::fetchIngredients() {
  std::vector<Ingredient> ingredients;
  sqlite3_stmt *stmt;
  std::string query = "SELECT id, name FROM ingredients;";

  if (sqlite3_prepare_v2(db_, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
    while (sqlite3_step(stmt) == SQLITE_ROW) {
      Ingredient ingredient;
      ingredient.id = sqlite3_column_int(stmt, 0);
      ingredient.name = QString::fromUtf8(
          reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
      ingredients.push_back(ingredient);
    }
  } else {
    std::cerr << "Failed to fetch ingredients: " << sqlite3_errmsg(db_)
              << std::endl;
  }

  sqlite3_finalize(stmt);
  return ingredients;
}

std::vector<Unit> SQLiteHelper::fetchUnits() {
  std::vector<Unit> units;
  sqlite3_stmt *stmt;
  std::string query = "SELECT id, name FROM units;";

  if (sqlite3_prepare_v2(db_, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
    while (sqlite3_step(stmt) == SQLITE_ROW) {
      Unit unit;
      unit.id = sqlite3_column_int(stmt, 0);
      unit.name = QString::fromUtf8(
          reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
      units.push_back(unit);
    }
  } else {
    std::cerr << "Failed to fetch units: " << sqlite3_errmsg(db_) << std::endl;
  }

  sqlite3_finalize(stmt);
  return units;
}

int SQLiteHelper::insertIngredient(Ingredient &ingredient) {
    // Local variables
    std::string query = "SELECT id FROM ingredients WHERE name = ?";
    sqlite3_stmt *stmt = nullptr; // Initialize to nullptr

    if (sqlite3_prepare_v2(db_, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, ingredient.name.toStdString().c_str(), -1, SQLITE_TRANSIENT);
        // Ensure stmt is finalized immediately after use
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            ingredient.id = sqlite3_column_int(stmt, 0);
            sqlite3_finalize(stmt);
            return ingredient.id;
        }
        sqlite3_finalize(stmt); // Finalize stmt in every exit path
    }
    // Prepare and execute the insert if the ingredient doesn't exist
    query = "INSERT INTO ingredients (name) VALUES (?)";
    if (sqlite3_prepare_v2(db_, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, ingredient.name.toStdString().c_str(), -1, SQLITE_TRANSIENT);
        if (sqlite3_step(stmt) == SQLITE_DONE) {
            ingredient.id = sqlite3_last_insert_rowid(db_);
        }
        sqlite3_finalize(stmt); // Finalize stmt
    }
    return ingredient.id;
}


int SQLiteHelper::insertUnit(Unit &unit) {
  // Check if unit exists
  std::string query = "SELECT id FROM units WHERE name = ?";
  sqlite3_stmt *stmt = nullptr;
  if (sqlite3_prepare_v2(db_, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
    sqlite3_bind_text(stmt, 1, unit.name.toStdString().c_str(), -1,
                      SQLITE_TRANSIENT);
    if (sqlite3_step(stmt) == SQLITE_ROW) {
      unit.id = sqlite3_column_int(stmt, 0); // Fetch existing ID
      sqlite3_finalize(stmt);
      return unit.id;
    }
  }
  sqlite3_finalize(stmt);

  // Insert new unit
  query = "INSERT INTO units (name) VALUES (?)";
  if (sqlite3_prepare_v2(db_, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
    sqlite3_bind_text(stmt, 1, unit.name.toStdString().c_str(), -1,
                      SQLITE_TRANSIENT);
    if (sqlite3_step(stmt) == SQLITE_DONE) {
      unit.id = sqlite3_last_insert_rowid(db_); // Fetch new ID
    }
  }
  sqlite3_finalize(stmt);
  return unit.id;
}

int SQLiteHelper::insertRecipe(Recipe &recipe) {
  std::string query =
      "INSERT INTO recipes (title, description, instructions) VALUES (?, ?, ?)";
  sqlite3_stmt *stmt = nullptr;
  int recipeId = -1;
  if (sqlite3_prepare_v2(db_, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
    sqlite3_bind_text(stmt, 1, recipe.title.toStdString().c_str(), -1,
                      SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, recipe.description.toStdString().c_str(), -1,
                      SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, recipe.instructions.toStdString().c_str(), -1,
                      SQLITE_TRANSIENT);
    if (sqlite3_step(stmt) == SQLITE_DONE) {
      recipeId = sqlite3_last_insert_rowid(db_);
    }
  }

  sqlite3_finalize(stmt);
  return recipeId;
}

bool SQLiteHelper::insertRecipeIngredientMap(int recipeId,
                                             Ingredient &ingredient,
                                             float quantity, Unit &unit) {
  std::string query = "INSERT INTO recipe_ingredients (recipe_id, "
                      "ingredient_id, quantity, unit_id) VALUES (?, ?, ?, ?)";
  sqlite3_stmt *stmt = nullptr;
  bool success = false;
  if (sqlite3_prepare_v2(db_, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
    sqlite3_bind_int(stmt, 1, recipeId);
    sqlite3_bind_int(stmt, 2, ingredient.id);
    sqlite3_bind_double(stmt, 3, static_cast<double>(quantity));
    sqlite3_bind_int(stmt, 4, unit.id);
    if (sqlite3_step(stmt) == SQLITE_DONE) {
      success = true;
    }
  }
  sqlite3_finalize(stmt);
  return success;
}
