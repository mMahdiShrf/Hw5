#ifndef INGREDIENT_H
#define INGREDIENT_H

class Ingredient // abstract class that we use for different types of ingredients
{
public:
    double get_price_unit() { return price_unit;}
    size_t get_units() { return units; }
    virtual std::string get_name() = 0;  // string::name should be defined by each class individualy
    double price() {return units * price_unit;}
    
    

protected:
    Ingredient(double _price_unit, size_t _units) // user can't make ingredients 
    :price_unit{_price_unit}
    ,units{_units} 
    {}

    double price_unit;
    size_t units;
    std::string name;
};

#endif // INGREDIENT_H