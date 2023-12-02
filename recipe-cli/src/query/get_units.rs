#[path="../models.rs"] mod models;
#[path="../schema.rs"] mod schema;
#[path="../lib.rs"] mod lib;
use models::*;
use diesel::prelude::*;

pub fn main() -> Vec<models::Unit>{
    let connection = &mut lib::establish_connection();
    let results = schema::unit::table
        .load(connection)
        .expect("Error loading recipes");
    return results
}
