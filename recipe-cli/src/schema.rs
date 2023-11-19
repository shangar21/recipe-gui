// @generated automatically by Diesel CLI.
diesel::table! {
    ingredient (id) {
        id -> Integer,
        recipe_id -> Integer,
        #[sql_name = "ingredient"]
        ingredient_name -> Text,
        amount -> Float,
        unit -> Integer,
    }
}

diesel::table! {
    recipe (id) {
        id -> Integer,
        name -> Text,
        description -> Text,
        instructions -> Text,
    }
}

diesel::table! {
    unit (id) {
        id -> Integer,
        #[sql_name = "unit"]
        unit_name -> Text,
    }
}

diesel::table! {
    unit_conversion (id) {
        id -> Integer,
        unit_from -> Integer,
        unit_to -> Integer,
        coefficient -> Float,
    }
}

diesel::joinable!(ingredient -> recipe (recipe_id));
diesel::joinable!(ingredient -> unit (unit));

diesel::allow_tables_to_appear_in_same_query!(
    ingredient,
    recipe,
    unit,
    unit_conversion,
);
