#include <iostream>

class Item
{
    int code;
    float price;
    std::string name;
    int quantity;

public:
    Item() {}
    Item(int, int, std::string, int);
    int getCode(void);
    float getPrice(void);
    std::string getName(void);
    int getQuantity(void);
    float getCost(void);
};

class Store
{
    static int count;
    static int itemCount;
    Item item[10];
    Item cart[5];

public:
    Store() {}
    void setItem(Item);
    void addToCart(Item);
    void removeFromCart(int);
    void display(void);
    void showCart(void);
};

int Store::count = 0;
int Store::itemCount = 0;

void Store::setItem(Item i)
{
    count++;
    if (count < 10)
    {
        item[count] = i;
    }
    else
    {
        std::cout << "Store is full!" << std::endl;
    }
}

void Store::addToCart(Item i)
{
    itemCount++;
    if (itemCount < 5)
    {
        cart[itemCount] = i;
    }
    else
    {
        std::cout << "Cart is full!" << std::endl;
    }
}

void Store::removeFromCart(int code)
{
    for (int i = 0; i < itemCount; i++)
    {
        if (cart[i].getCode() == code)
        {
            for (int j = i; j < itemCount; j++)
            {
                cart[j] = cart[j + 1];
            }
            itemCount--;
            break;
        }
    }
}

void Store::display(void)
{
    std::cout << "------------------Store------------------" << std::endl;
    std::cout << "Item Code\tPrice\tName\tQuantity\tCost" << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << item[i].getCode() << "\t\t" << item[i].getPrice() << "\t" << item[i].getName() << "\t" << item[i].getQuantity() << "\t\t" << item[i].getCost() << std::endl;
    }
}

void Store::showCart(void)
{
    std::cout << "------------------Cart------------------" << std::endl;
    std::cout << "Item Code\tPrice\tName\tQuantity\tCost" << std::endl;
    for (int i = 0; i < itemCount; i++)
    {
        std::cout << cart[i].getCode() << "\t\t" << cart[i].getPrice() << "\t" << cart[i].getName() << "\t" << cart[i].getQuantity() << "\t\t" << cart[i].getCost() << std::endl;
    }
}

Item::Item(int c, int p, std::string n, int q)
{
    code = c;
    price = p;
    name = n;
    quantity = q;
}

int Item::getCode()
{
    return code;
}

float Item::getPrice()
{
    return price;
}

std::string Item::getName()
{
    return name;
}

int Item::getQuantity()
{
    return quantity;
}

float Item::getCost()
{
    return price * quantity;
}

int main()
{
    Store store;
    Item item1(1, 100, "Item 1", 1);
    Item item2(2, 200, "Item 2", 2);
    Item item3(3, 300, "Item 3", 3);
    Item item4(4, 400, "Item 4", 4);
    Item item5(5, 500, "Item 5", 5);
    Item item6(6, 600, "Item 6", 6);
    Item item7(7, 700, "Item 7", 7);
    Item item8(8, 800, "Item 8", 8);
    Item item9(9, 900, "Item 9", 9);
    Item item10(10, 1000, "Item 10", 10);

    store.setItem(item1);
    store.setItem(item2);
    store.setItem(item3);
    store.setItem(item4);
    store.setItem(item5);
    store.setItem(item6);
    store.setItem(item7);
    store.setItem(item8);
    store.setItem(item9);
    store.setItem(item10);

    store.display();

    store.addToCart(item1);
    store.addToCart(item2);
    store.addToCart(item3);
    store.addToCart(item4);
    store.addToCart(item5);

    store.showCart();

    store.removeFromCart(3);

    store.showCart();



    return 0;
};