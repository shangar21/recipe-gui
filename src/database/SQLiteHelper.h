#pragma once
#include "models.h"
#include <QString>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>
#include <QDebug>

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
  int insertIngredient(Ingredient &ingredient);
  int insertUnit(Unit &unit);
  int insertRecipe(Recipe &recipe);
  bool insertRecipeIngredientMap(int recipeId, Ingredient &ingredient,
                                 float quantity, Unit &unit);
  std::vector<std::tuple<Ingredient, float, Unit>>
  fetchRecipeIngredients(int recipeId);
	

private:
  sqlite3 *db_;
};
