use cursive::views::{Dialog, TextView};
#[path="../lib.rs"] mod lib;
#[path="../models.rs"] mod models;
#[path="./view_recipes.rs"] mod view_recipes;
#[path="./add_recipe.rs"] mod add_recipe;

pub fn main() {
    let mut siv = cursive::default();

    siv.add_layer(Dialog::around(TextView::new("Welcome to Recipe CLI!"))
                         .title("Recipe CLI")
                         .button("Add Recipe", |s| add_recipe::add_recipe(s))
                         .button("View Recipes", |s| view_recipes::view_recipes(s))
                         .button("Generate Grocery List", |s| s.quit())
                         .button("Quit", |s| s.quit()));

    siv.run();
}
