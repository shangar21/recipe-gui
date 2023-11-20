use cursive::views::{Dialog, TextView, ListView, EditView, Menubar, BoxedView, LinearLayout};
use cursive::Cursive;
use cursive::menu;
#[path="../query/get_recipes.rs"] mod get_recipes;

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
        view.add_leaf(
            &i.name.clone(),
            move |s| {
                s.add_layer(
                   LinearLayout::vertical()
                   .child(Dialog::around(TextView::new(&i.name.clone())))
                   .child(Dialog::around(TextView::new(&i.description.clone())).title("Description"))
                   .child(Dialog::around(TextView::new(&i.instructions.clone())).title("instructions").dismiss_button("Back"))
                )
            }
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
