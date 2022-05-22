#include "mocha.h"

// implementing this class is same ass Cappuccino class
// they just have minor difference in their ingredients

Mocha::Mocha()
:EspressoBased()
,side_items{}
{   
    name = "Mocha";
    Milk* milk{new Milk{2}};
    ingredients.push_back(milk);
    Espresso* espresso{new Espresso{2}};
    ingredients.push_back(espresso);
    MilkFoam* milkfoam{new MilkFoam{1}};
    ingredients.push_back(milkfoam);
    Chocolate* chocolate {new Chocolate{1}};
    ingredients.push_back(chocolate);
}

Mocha::Mocha(const Mocha& cap)
:EspressoBased{cap}
{
    for(const auto& i : cap.side_items)
    {
        if (i->get_name()=="Cinnamon")
            side_items.push_back(new Cinnamon{i->get_units()});

        if (i->get_name()=="Chocolate")
            side_items.push_back(new Chocolate{i->get_units()});

        if (i->get_name()=="Sugar")
            side_items.push_back(new Sugar{i->get_units()});

        if (i->get_name()=="Cookie")
            side_items.push_back(new Cookie{i->get_units()});

        if (i->get_name()=="Espresso")
            side_items.push_back(new Espresso{i->get_units()});

        if (i->get_name()=="Milk")
            side_items.push_back(new Milk{i->get_units()});
        
        if (i->get_name()=="MilkFoam")
            side_items.push_back(new MilkFoam{i->get_units()});

        if (i->get_name()=="Water")
            side_items.push_back(new Water{i->get_units()});
    }
}

Mocha::~Mocha()
{  
    for(const auto& i : side_items)
    delete i;
    side_items.clear();
}

std::string Mocha::get_name()
{
    return name;
}

double Mocha::price()
{   
    double price{};
    for(const auto&  i: ingredients)
        price += i->get_units()*i->get_price_unit();
    
    for(const auto& i : side_items)
        price += i->get_units()*i->get_price_unit();
        
    return price;
}

void Mocha::add_side_item(Ingredient* side)
{
    side_items.push_back(side);
}

std::vector<Ingredient*>& Mocha::get_side_items()
{
    return side_items;
}

void Mocha::operator=(const Mocha& cap)
{   
    if(this == &cap)
        return;
    else
        side_items.clear();
    for(const auto& i : cap.side_items)
    {
        if (i->get_name()=="Cinnamon")
            side_items.push_back(new Cinnamon{i->get_units()});

        if (i->get_name()=="Chocolate")
            side_items.push_back(new Chocolate{i->get_units()});

        if (i->get_name()=="Sugar")
            side_items.push_back(new Sugar{i->get_units()});

        if (i->get_name()=="Cookie")
            side_items.push_back(new Cookie{i->get_units()});

        if (i->get_name()=="Espresso")
            side_items.push_back(new Espresso{i->get_units()});

        if (i->get_name()=="Milk")
            side_items.push_back(new Milk{i->get_units()});
        
        if (i->get_name()=="MilkFoam")
            side_items.push_back(new MilkFoam{i->get_units()});

        if (i->get_name()=="Water")
            side_items.push_back(new Water{i->get_units()});
    }
}