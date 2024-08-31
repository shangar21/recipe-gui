#ifndef MODELS_H
#define MODELS_H

#include <QMetaType>
#include <QString>

struct Recipe {
  int id;
  QString title;
  QString description;
  QString instructions;
};
Q_DECLARE_METATYPE(Recipe)

struct Ingredient {
  int id;
  QString name;
};

struct Unit {
  int id;
  QString name;
};

struct UnitConversions {
  int id;
  int from_id;
  int to_id;
  float factor;
};

struct RecipeIngredients {
  int id;
  int recipe_id;
  int ingredient_id;
  float quantity;
  int unit_id;
};

#endif
