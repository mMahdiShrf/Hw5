#ifndef CAPPUCCINO
#define CAPPUCCINO

#include <string>
#include "espresso_based.h"
#include "sub_ingredients.h"


class Cappuccino : public EspressoBased
{
public:
    Cappuccino();
    Cappuccino(const Cappuccino& cap);
	virtual ~Cappuccino();
    void operator=(const Cappuccino& cap);

    virtual std::string get_name();
    virtual double price();

    void add_side_item(Ingredient* side);
    std::vector<Ingredient*>& get_side_items();
private:
    std::vector<Ingredient*> side_items;

};

#endif // CAPPUCCINO