#include "espresso_based.h"

EspressoBased::EspressoBased()
:ingredients{}
,name{}
{}

EspressoBased::~EspressoBased()
{
    for(const auto& i : ingredients)
    delete i;
    ingredients.clear();
}

std::vector<Ingredient*>& EspressoBased::get_ingredients()
{
    return ingredients;
}

EspressoBased::EspressoBased(const EspressoBased& esp)
:ingredients{}
,name{esp.name}
{   
    for(const auto& i : esp.ingredients)
    {
        if (i->get_name()=="Cinnamon")
            ingredients.push_back(new Cinnamon{i->get_units()});
        if (i->get_name()=="Chocolate")
            ingredients.push_back(new Chocolate{i->get_units()});

        if (i->get_name()=="Sugar")
            ingredients.push_back(new Sugar{i->get_units()});

        if (i->get_name()=="Cookie")
            ingredients.push_back(new Cookie{i->get_units()});

        if (i->get_name()=="Espresso")
            ingredients.push_back(new Espresso{i->get_units()});

        if (i->get_name()=="Milk")
            ingredients.push_back(new Milk{i->get_units()});
        
        if (i->get_name()=="MilkFoam")
            ingredients.push_back(new MilkFoam{i->get_units()});

        if (i->get_name()=="Water")
            ingredients.push_back(new Water{i->get_units()});
    }

}

void EspressoBased::operator= (EspressoBased& esp)
{

}

void EspressoBased::brew()
{   
    using namespace std::chrono_literals;
    int index{0};
    auto title = ftxui::vbox({
        ftxui::text(" Your " + this->get_name() + " is brewing :") |ftxui::borderDouble
        | ftxui::color(ftxui::Color::RedLight)
    });
    auto title_screen =
    ftxui::Screen::Create(ftxui::Dimension::Fit(title), ftxui::Dimension::Fit(title));
    ftxui::Render(title_screen, title);
    title_screen.Print();
    std::cout << std::endl;
    for(const auto& i:ingredients)
    {   
        index++;
        ftxui::Element document =
            ftxui::hbox({
            ftxui::text(std::to_string(index)+"." + "brewing "+
            i->get_name() + " for " +
            std::to_string(i->get_units()) + " units"
            ) | ftxui::border | ftxui::color(ftxui::Color::MagentaLight)
            });

        auto screen = ftxui::Screen::Create(
            ftxui::Dimension::Full(),       // Width
            ftxui::Dimension::Fit(document) // Height
        );
        ftxui::Render(screen, document);
        screen.Print();
        std::string reset_position;
        for (float percentage = 0.0; percentage <= 1.01f; percentage += 0.01f) {
            std::string brewed =
                std::to_string(int(percentage * 100)) + "/100";
            auto gauge_document = ftxui::hbox({
                ftxui::text("brewing: ") | ftxui::color(ftxui::Color::Blue),
                ftxui::gauge(percentage) | ftxui::flex | ftxui::color(ftxui::Color::Blue),
                ftxui::text(" " + brewed) | ftxui::color(ftxui::Color::Blue),
            });
            auto gauge_screen = ftxui::Screen(100, 1);
            ftxui::Render(gauge_screen, gauge_document);
            std::cout << reset_position;
            gauge_screen.Print();
            reset_position = gauge_screen.ResetPosition();
            std::this_thread::sleep_for(i->get_units()*0.01s);
        }
        std::cout << std::endl;
    }
    auto footer = ftxui::vbox({
        ftxui::text(" Your " + this->get_name() + " is brewed ") |ftxui::borderDouble
        | ftxui::color(ftxui::Color::Green)
    });
    auto footer_screen =
    ftxui::Screen::Create(ftxui::Dimension::Fit(footer), ftxui::Dimension::Fit(footer));
    ftxui::Render(footer_screen, footer);
    footer_screen.Print();
    std::cout << std::endl;
}
