#[path="../models.rs"] mod models;
#[path="../schema.rs"] mod schema;
#[path="../lib.rs"] mod lib;
use models::*;
use diesel::prelude::*;

pub fn main() -> Vec<models::Recipe>{
    let connection = &mut lib::establish_connection();
    let results = schema::recipe::table
        .select(diesel::dsl::max(schema::recipe::id))
        .load(connection)
        .expect("Error loading recipes");
    return results
}
