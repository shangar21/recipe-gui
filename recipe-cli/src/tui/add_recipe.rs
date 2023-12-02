use cursive::views::{Dialog, TextView, ListView, EditView, Menubar, BoxedView, LinearLayout, TextArea, ListChild, ResizedView, NamedView};
use cursive::view::{Resizable, Nameable, Scrollable};
use cursive::Cursive;
use cursive::menu;
#[path="../query/add_recipes.rs"] mod add_recipes;
#[path="../query/get_recipe_max_id.rs"] mod get_recipe_id;
#[path="../models.rs"] mod models;

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

fn submit_form(name: &str, desc: &str, instr: &str){
    let recipe = models::Recipe();
    recipe.id = get_recipe_id::main() + 1;
}

pub fn add_recipe(s: &mut Cursive){
    let form = generate_recipe_form();
    s.add_layer(
        Dialog::around(
            TextView::new("Add Recipes")
        )
        .title("Add Recipe")
        .button("Quit", |s| s.quit())
        .button("Submit", move |s| {
            s.pop_layer();
            submit_form(
                s.find_name::<TextArea>("recipe_name").unwrap().get_content(),
                s.find_name::<TextArea>("recipe_description").unwrap().get_content(),
                s.find_name::<TextArea>("recipe_instructions").unwrap().get_content()
            )
        })
        .dismiss_button("Back")
        .content(
            form
        )
    );
}
