#[path="../models.rs"] mod models;
#[path="../schema.rs"] mod schema;
#[path="../lib.rs"] mod lib;
use models::*;
use diesel::prelude::*;

pub fn main(ingredient: models::Ingredient) {
    let connection = &mut lib::establish_connection();
    let results = diesel::insert_into(schema::ingredient)
        .values(ingredient)
        .execute(connection)
        .expect("Error adding recipes");
    return results
}
