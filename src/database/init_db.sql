-- Create the table for recipes
CREATE TABLE IF NOT EXISTS recipes (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    title TEXT NOT NULL,
    description TEXT,
    instructions TEXT
);

-- Create the table for ingredients
CREATE TABLE IF NOT EXISTS ingredients (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL UNIQUE
);

-- Create the table for units
CREATE TABLE IF NOT EXISTS units (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL UNIQUE
);

-- Create the mapping table for recipe ingredients
-- This table links recipes to their ingredients with quantities and units
CREATE TABLE IF NOT EXISTS recipe_ingredients (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    recipe_id INTEGER NOT NULL,
    ingredient_id INTEGER NOT NULL,
    quantity REAL NOT NULL,
    unit_id INTEGER NOT NULL,
    FOREIGN KEY (recipe_id) REFERENCES recipes(id) ON DELETE CASCADE,
    FOREIGN KEY (ingredient_id) REFERENCES ingredients(id) ON DELETE CASCADE,
    FOREIGN KEY (unit_id) REFERENCES units(id) ON DELETE CASCADE
);

-- Create a table for unit conversions if needed
-- This table maps units to their conversion rates relative to a standard unit
CREATE TABLE IF NOT EXISTS unit_conversions (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    from_unit_id INTEGER NOT NULL,
    to_unit_id INTEGER NOT NULL,
    factor REAL NOT NULL, -- The factor to multiply by from_unit to convert to to_unit
    FOREIGN KEY (from_unit_id) REFERENCES units(id) ON DELETE CASCADE,
    FOREIGN KEY (to_unit_id) REFERENCES units(id) ON DELETE CASCADE,
    UNIQUE(from_unit_id, to_unit_id) -- Ensure unique conversions between any two units
);

