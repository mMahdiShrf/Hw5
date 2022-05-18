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
