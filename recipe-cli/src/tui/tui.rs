use cursive::views::{Dialog, TextView};
#[path="../lib.rs"] mod lib;
#[path="../models.rs"] mod models;
#[path="./view_recipes.rs"] mod view_recipes;

pub fn main() {
    let mut siv = cursive::default();

    siv.add_layer(Dialog::around(TextView::new("Welcome to Recipe CLI!"))
                         .title("Recipe CLI")
                         .button("Add Recipe", |s| s.quit())
                         .button("View Recipes", |s| view_recipes::view_recipes(s))
                         .button("Generate Grocery List", |s| s.quit())
                         .button("Quit", |s| s.quit()));

    siv.run();
}
