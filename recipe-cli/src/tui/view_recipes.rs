use cursive::views::{Dialog, TextView, ListView, EditView, Menubar};
use cursive::Cursive;
use cursive::menu;
#[path="../query/get_recipes.rs"] mod get_recipes;
#[path="../tui/display_recipe_information.rs"] mod display_recipe_information;

fn generate_recipe_list() ->  Menubar{
    let results = get_recipes::main();
    let mut view = Menubar::new();

    if results.len() == 0 {
        view.add_subtree(
            "Recipes",
            cursive::menu::Tree::new()
            .leaf("No Recipes Currently, Add Some!", move |s| {})
        );
        return view;
    }

    for i in results{
        view.add_subtree(
            &i.name,
            cursive::menu::Tree::new()
            .leaf(&i.name, move |s| {
                display_recipe_information::display_info(s, &i.name, &i.description)
            })
        );
    }

    return view;
}

pub fn view_recipes(s: &mut Cursive){
    s.add_layer(
        Dialog::around(
            TextView::new("View Recipes")
        )
        .button("Quit", |s| s.quit())
        .dismiss_button("Back")
        .content(
            generate_recipe_list()
        )
    );
}



