use diesel::prelude::*;
#[path="./schema.rs"] mod schema;

#[derive(Queryable, Selectable, Insertable)]
#[diesel(table_name = schema::unit)]
#[diesel(check_for_backend(diesel::sqlite::Sqlite))]
pub struct Unit {
    pub id: i32,
    pub unit_name: String
}

#[derive(Queryable, Selectable, Insertable)]
#[diesel(table_name = schema::unit_conversion)]
#[diesel(check_for_backend(diesel::sqlite::Sqlite))]
pub struct UnitConversion {
    pub id: i32,
    pub unit_from: i32,
    pub unit_to: i32,
    pub coefficient: f32
}

#[derive(Queryable, Selectable, Insertable)]
#[diesel(table_name = schema::ingredient)]
#[diesel(check_for_backend(diesel::sqlite::Sqlite))]
pub struct Ingredient {
    pub id: i32,
    pub recipe_id: i32,
    pub ingredient_name: String,
    pub amount: f32,
    pub unit: i32
}

#[derive(Queryable, PartialEq, Debug, Selectable, Insertable)]
#[diesel(table_name = schema::recipe)]
#[diesel(check_for_backend(diesel::sqlite::Sqlite))]
pub struct Recipe {
    pub id: i32,
    pub name: String,
    pub description: String,
    pub instructions: String
}
