#ifndef CAPPUCCINO
#define CAPPUCCINO

#include <string>
#include "espresso_based.h"
#include "sub_ingredients.h"



class Cappuccino : public EspressoBased // this coffee is drived from EspressoBased Class
{
public:
    Cappuccino();
    Cappuccino(const Cappuccino& cap);
	virtual ~Cappuccino(); // for late bining
    void operator=(const Cappuccino& cap);

    virtual std::string get_name();
    virtual double price();

    void add_side_item(Ingredient* side);
    std::vector<Ingredient*>& get_side_items();
private:
    std::vector<Ingredient*> side_items;

};

#endif // CAPPUCCINO