use colored::Colorize;
use std::env;

macro_rules! borgir_item {
    ($string:literal) => {
        $string
            .strip_prefix("\n").unwrap_or_else(|| $string).to_string()
            .strip_suffix("\n").unwrap_or_else(|| $string).to_string()
    };

    ($string:literal, $color:ident) => {
        borgir_item!($string).$color().to_string()
    };

    ($string:literal, $r:literal, $g:literal, $b:literal) => {
        borgir_item!($string).truecolor($r, $g, $b).to_string()
    };

}

const DEFAULTS: &'static [&'static str] = &[
    "crown",
    "lettuce",
    "pickles",
    "cheese",
    "beef",
    "ketchup",
    "mustard",
    "bottom",
];

fn get_item(item: String, use_color: bool) -> String {
    match item.as_str() {
        "crown" =>
borgir_item!("
 ________________
/ . ,  .   , . . \\
|    .  ,   .   ,|
'‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾'
", bright_yellow),

        "lettuce" => borgir_item!("/\\/\\/\\/\\/\\/\\/\\/\\/", green),

        "pickles" => borgir_item!("o  o o  o o  o o", green),

        "cheese" => borgir_item!("/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\\",  yellow),

        "beef" => borgir_item!("
._______________.
| . ,  .   , . .|
'‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾'
", 139, 69, 19),

        "ketchup" => borgir_item!("~~~~~~~~~~~~~~~~~", red),
        "mustard" => borgir_item!("~~~~~~~~~~~~~~~~~", yellow),
        "mayo" => borgir_item!("~~~~~~~~~~~~~~~~~"),

        "bottom" => borgir_item!("
._______________.
| . ,  .   , . .|
|  .  ,   ,    .|
'‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾'
", bright_yellow),

        "please" => borgir_item!("
please cheese or bees
please burger cheese
"),

        _ =>
            format!("Unknown item {}", item).red().to_string()
    }
}

fn borgir(use_color: bool) -> String {
    let mut default_borgir: String = "".to_string();

    for (i, v) in DEFAULTS.into_iter().enumerate() {
        default_borgir.push_str(get_item(v.to_string(), use_color).as_str());
        if i != DEFAULTS.len() - 1 { default_borgir += "\n"; }
    }

    default_borgir
}

fn main() -> Result<(), ()> {
    // Prints each argument on a separate line
    if env::args().len() == 1 {
        println!("{}", borgir(true));
        return Ok(());
    }
    for (i, arg) in env::args().enumerate() {
        if i == 0 { continue };
        if arg == "borgir" {
            println!("{}", borgir(true));
        } else {
            println!("{}", get_item(arg, true));
        }
    }

    Ok(())
}
