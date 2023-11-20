use cursive::views::{Dialog, TextView, ListView, EditView, Menubar, BoxedView, LinearLayout, TextArea};
use cursive::view::{Resizable, Nameable};
use cursive::Cursive;
use cursive::menu;
#[path="../query/get_recipes.rs"] mod get_recipes;

fn generate_recipe_form() -> ListView {
    let mut view = ListView::new();

    let mut recipe_name = TextArea::new()
        .with_name("recipe_name")
        .fixed_width(30)
        .min_height(5);

    let mut recipe_description = TextArea::new()
        .with_name("recipe_description")
        .fixed_width(30)
        .min_height(5);

    let mut recipe_instructions = TextArea::new()
        .with_name("recipe_instructions")
        .fixed_width(30)
        .min_height(5);

    view.add_child("Recipe Name", recipe_name);
    view.add_delimiter();
    view.add_child("Recipe Description", recipe_description);
    view.add_delimiter();
    view.add_child("Recipe Instructions", recipe_instructions);

    return view;
}

fn submit_form(name: &str, desc: &str, instr: &str){}

pub fn add_recipe(s: &mut Cursive){
    let form = generate_recipe_form();
    s.add_layer(
        Dialog::around(
            TextView::new("Add Recipes")
        )
        .title("Add Recipe")
        .button("Quit", |s| s.quit())
        .button("Submit", |s| {
            s.pop_layer();
        })
        .dismiss_button("Back")
        .content(
            form
        )
    );
}
