#pragma once

#include <QString>

struct Recipe {
  int id;
  QString title;
  QString description;
  QString instructions;
};
Q_DECLARE_METATYPE(Recipe)
