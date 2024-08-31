#include "SQLiteHelper.h"

SQLiteHelper::SQLiteHelper(const std::string &db_path) {
  if (sqlite3_open(db_path.c_str(), &db_) != SQLITE_OK) {
    std::cerr << "Error opening database: " << db_path << " Error: "<< sqlite3_errmsg(db_) << std::endl;
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
  if (sqlite3_bind_text(stmt, 1, param.c_str(), -1, SQLITE_STATIC) !=
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
