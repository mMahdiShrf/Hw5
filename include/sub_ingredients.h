#ifndef SUB_INGREDIENTS_H
#define SUB_INGREDIENTS_H

#include <iostream>
#include "ingredient.h"

// using define to avoid code copy 
#define DEFCLASS(drived_class_name,price_unit)\
class drived_class_name: public Ingredient\
{ \
    public:\
    drived_class_name(size_t units) : Ingredient{price_unit, units}\ // sub_ingredeint drived from Ingredient
    {\
        this->name = #drived_class_name;\
    }\
    virtual std::string get_name() {return this->name;}\
};
// defining Ingredients that we want using our defined class
DEFCLASS(Cinnamon, 5);
DEFCLASS(Chocolate, 5);
DEFCLASS(Sugar, 1);
DEFCLASS(Cookie, 10);
DEFCLASS(Espresso, 15);
DEFCLASS(Milk, 10);
DEFCLASS(MilkFoam, 5);
DEFCLASS(Water, 1);


#endif // SUB_INGREDIENTS_H