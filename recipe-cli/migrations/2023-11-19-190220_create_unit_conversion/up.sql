-- Your SQL goes here
CREATE TABLE IF NOT EXISTS unit_conversion (
  id integer PRIMARY KEY,
  unit_from integer NOT NULL,
  unit_to integer NOT NULL,
  coefficient float NOT NULL,
  FOREIGN KEY (unit_from) REFERENCES unit (id),
  FOREIGN KEY (unit_to) REFERENCES unit (id)
)
