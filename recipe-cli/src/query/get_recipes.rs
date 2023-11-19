#[path="../models.rs"] mod models;
#[path="../schema.rs"] mod schema;
#[path="../lib.rs"] mod lib;
use models::*;
use diesel::prelude::*;
use diesel_demo::*;

fn main() -> {
    use schema::recipe::dsl::*;

    let connection = &mut lib::establish_connection();
    let results = recipe.select(models::Recipe::as_select())
        .load(connection)
        .expect("Error loading recipes");
}
