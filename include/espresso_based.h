#ifndef ESPRESSO_BASED_H
#define ESPRESSO_BASED_H

#include <string>
#include <vector>
#include "ingredient.h"
#include "sub_ingredients.h"

// libraries that we need for EspressoBased::brew
#include <cmath>                   // for cos
#include <chrono>                  // for operator""s, chrono_literals
#include <iostream>                 // for cout, endl, ostream
#include <string>  // for allocator, operator+, char_traits, operator<<, string, to_string, basic_string
#include <thread>  // for sleep_for
#include "ftxui/dom/node.hpp"      // for Render
#include "ftxui/screen/color.hpp"  // for ftxui
#include <ftxui/dom/elements.hpp>  // for Fit, canvas, operator|, border, Element
#include <ftxui/screen/screen.hpp>  // for Pixel, Screen

class EspressoBased // abstract class that we use for different types of coffee
{
public:
    virtual std::string get_name() = 0;
    virtual double price() = 0;

    void brew();
    std::vector<Ingredient*>& get_ingredients();
    void operator=(EspressoBased& esp);

    virtual ~EspressoBased(); // for late binding 

protected:
    EspressoBased();
    EspressoBased(const EspressoBased& esp);
    void operator=(const EspressoBased& esp);

    std::vector<Ingredient*> ingredients;
    std::string name;

};

#endif // ESPRESSO_BASED_H