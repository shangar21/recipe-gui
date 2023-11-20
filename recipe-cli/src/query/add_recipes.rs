#[path="../models.rs"] mod models;
#[path="../schema.rs"] mod schema;
#[path="../lib.rs"] mod lib;
use models::*;
use diesel::prelude::*;

pub fn main(recipe: models::Recipe) {
    let connection = &mut lib::establish_connection();
    let results = diesel::insert_into(schema::recipe)
        .values(&recipe)
        .execute(connection)
        .expect("Error adding recipes");
    return results
}
