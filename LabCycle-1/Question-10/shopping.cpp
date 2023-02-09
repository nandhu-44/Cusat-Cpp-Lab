#include <iostream>

class Item;

class Store
{
    Item item;

public:
    Store() {}
    Store(Item);
};

Store::Store(Item i)
{
    item = i;
}

class Item
{
    int code;
    float price;
    std::string name;
    int quantity;

public:
    Item() {}
    Item(int, int, std::string, int);
    float getCost(void);
};

Item::Item(int c, int p, std::string n, int q)
{
    code = c;
    price = p;
    name = n;
    quantity = q;
}

Item::getCost()
{
    return price * quantity;
}