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
:ingredients {std::vector<Ingredient*>{esp.ingredients}}
,name{esp.name}
{}
void EspressoBased::operator= (EspressoBased& esp)
{
    ingredients = esp.ingredients;
    name = esp.name;
}
