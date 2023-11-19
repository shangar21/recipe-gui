-- Your SQL goes here
CREATE TABLE IF NOT EXISTS recipe (
  id integer PRIMARY KEY,
  name varchar NOT NULL,
  description text NOT NULL,
  instructions text NOT NULL
);

CREATE TABLE IF NOT EXISTS ingredient (
  id integer PRIMARY KEY,
  recipe_id integer NOT NULL,
  ingredient varchar NOT NULL,
  amount float NOT NULL,
  unit integer NOT NULL,
  FOREIGN KEY (recipe_id) REFERENCES recipe (id),
  FOREIGN KEY (unit) REFERENCES unit (id)
);
