#pragma once
#include "models.h"
#include <QString>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>

class SQLiteHelper {
public:
  SQLiteHelper(const std::string &db_path = DB_PATH);
  ~SQLiteHelper();

  bool executeQuery(const std::string &query);
  bool executeParameterizedQuery(const std::string &query,
                                 const std::string &param);
  std::vector<Recipe> fetchRecipes();
  std::vector<Ingredient> fetchIngredients();
  std::vector<Unit> fetchUnits();

private:
  sqlite3 *db_;
};
