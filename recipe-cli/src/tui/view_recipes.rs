use cursive::views::{Dialog, TextView};
use cursive::Cursive;

fn get_recipes() {

}

pub fn view_recipes(s: &mut Cursive){
    s.pop_layer();
    s.add_layer(Dialog::around(TextView::new("View Recipes"))
                         .button("Quit", |s| s.quit()));
}
