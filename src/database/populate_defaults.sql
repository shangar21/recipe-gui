-- Insert default ingredients
INSERT INTO ingredients (name) VALUES 
    ('Onion'),
    ('Garlic'),
    ('Carrot'),
    ('Tomato'),
    ('Potato'),
    ('Chicken'),
    ('Beef'),
    ('Salt'),
    ('Pepper');

-- Insert default units
INSERT INTO units (name) VALUES 
    ('grams'),
    ('kilograms'),
    ('milliliters'),
    ('liters'),
    ('cups'),
    ('tablespoons'),
    ('teaspoons'),
    ('pieces');

-- Insert default unit conversions
-- Example conversions assuming a standard base unit:
-- For simplicity, let's assume the base unit is 'grams' for weight, 'milliliters' for volume
INSERT INTO unit_conversions (from_unit_id, to_unit_id, factor) VALUES 
    -- Grams to Kilograms and vice versa
    ((SELECT id FROM units WHERE name = 'grams'), (SELECT id FROM units WHERE name = 'kilograms'), 0.001),
    ((SELECT id FROM units WHERE name = 'kilograms'), (SELECT id FROM units WHERE name = 'grams'), 1000),

    -- Milliliters to Liters and vice versa
    ((SELECT id FROM units WHERE name = 'milliliters'), (SELECT id FROM units WHERE name = 'liters'), 0.001),
    ((SELECT id FROM units WHERE name = 'liters'), (SELECT id FROM units WHERE name = 'milliliters'), 1000),

    -- Tablespoons to Teaspoons and vice versa
    ((SELECT id FROM units WHERE name = 'tablespoons'), (SELECT id FROM units WHERE name = 'teaspoons'), 3),
    ((SELECT id FROM units WHERE name = 'teaspoons'), (SELECT id FROM units WHERE name = 'tablespoons'), 0.3333),

    -- Cups to Milliliters and vice versa
    ((SELECT id FROM units WHERE name = 'cups'), (SELECT id FROM units WHERE name = 'milliliters'), 240),
    ((SELECT id FROM units WHERE name = 'milliliters'), (SELECT id FROM units WHERE name = 'cups'), 0.00417);

