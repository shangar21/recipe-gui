use cursive::views::{Dialog, TextView, ListView, EditView, Menubar};
use cursive::Cursive;
use cursive::menu;
#[path="../models.rs"] mod models;

pub fn display_info(s: &mut Cursive, name: &str, description: &str){
    s.add_layer(
        Dialog::around(
            TextView::new(name)
        )
        .dismiss_button("Back")
        .content(TextView::new(description))
    );
}
