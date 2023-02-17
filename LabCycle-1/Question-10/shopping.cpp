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
    void setQuantity(int);
    float getCost(void);
};

class Store
{
    static int count;
    static int itemCount;
    Item *item;
    Item *cart;

public:
    Store();
    void setItem(Item);
    void addToCart(int, int);
    Item getItem(int);
    void removeFromCart(int, int);
    void display(void);
    void showCart(void);
    static int getCount(void);
    void confirmPurchase(void);
    ~Store();
};

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

void Item::setQuantity(int newQuantity)
{
    quantity = newQuantity;
}

float Item::getCost()
{
    return price * quantity;
}

int Store::count = 0;
int Store::itemCount = 0;

Store::Store()
{
    item = new Item[6];
    cart = new Item[3];
}

void Store::setItem(Item i)
{
    if (count < 6)
    {
        item[count] = i;
        count++;
    }
    else
    {
        std::cout << "Store is full!" << std::endl;
    }
}

void Store::addToCart(int code, int quantity)
{
    if (code < 1 || code > 6)
    {
        std::cout << "Item does not exist in the store!" << std::endl;
    }
    else
    {
        if (itemCount < 3)
        {
            for (int i = 0; i < count; i++)
            {
                if (item[i].getCode() == code)
                {
                    if (item[i].getQuantity() >= quantity)
                    {
                        cart[itemCount] = item[i];
                        cart[itemCount].setQuantity(quantity);
                        itemCount++;
                        int newQuantity = item[i].getQuantity() - quantity;
                        item[i].setQuantity(newQuantity);
                        break;
                    }
                    else
                    {
                        std::cout << "Item out of stock!" << std::endl;
                    }
                }
            }
        }
        else
        {
            std::cout << "Cart is full!" << std::endl;
        }
    }
}

void Store::removeFromCart(int code, int quantity)
{
    if (code < 1 || code > 6)
    {
        std::cout << "Item does not exist in the store" << std::endl;
    }
    else
    {
        if (itemCount == 0)
        {
            std::cout << "Your cart is empty!" << std::endl;
        }
        else
        {
            bool itemFound = false;
            for (int i = 0; i < itemCount; i++)
            {
                if (cart[i].getCode() == code)
                {
                    itemFound = true;
                    if (cart[i].getQuantity() >= quantity)
                    {
                        cart[i].setQuantity(cart[i].getQuantity() - quantity);
                        for (int j = 0; j < count; j++)
                        {
                            if (item[j].getCode() == code)
                            {
                                item[j].setQuantity(item[j].getQuantity() + quantity);
                                break;
                            }
                        }
                        break;
                    }
                    else
                    {
                        std::cout << "You haven't purchased that many quantities of the item!" << std::endl;
                    }
                }
            }
            if (!itemFound)
            {
                std::cout << "That item is not in the cart" << std::endl;
            }
        }
    }
}

Item Store::getItem(int code)
{
    for (int i = 0; i < count; i++)
    {
        if (item[i].getCode() == code)
        {
            return item[i];
        }
    }
    return Item();
}

void Store::display(void)
{
    std::cout << "------------------Store------------------" << std::endl;
    std::cout << "Item Code\tName\tPrice\tQuantity" << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << item[i].getCode() << "\t\t" << item[i].getName() << "\t" << item[i].getPrice() << "\t" << item[i].getQuantity() << std::endl;
    }
}

void Store::showCart(void)
{
    std::cout << "------------------Cart------------------" << std::endl;
    std::cout << "Item Code\tName\tPrice\t\tQuantity\tCost" << std::endl;
    for (int i = 0; i < itemCount; i++)
    {
        std::cout << "  " << cart[i].getCode() << "\t\t"
                  << " " << cart[i].getName() << "\t"
                  << cart[i].getPrice() << "\t\t"
                  << "  " << cart[i].getQuantity() << "\t\t"
                  << " " << cart[i].getCost() << std::endl;
    }
}

int Store::getCount(void)
{
    return count;
}

void Store::confirmPurchase(void)
{
    std::cout << "----------------------------Bill----------------------------" << std::endl;
    std::cout << "Item Code\tName\tPrice\t\tQuantity\tCost" << std::endl;
    int total = 0;
    for (int i = 0; i < itemCount; i++)
    {
        std::cout << "  " << cart[i].getCode() << "\t\t"
                  << " " << cart[i].getName() << "\t"
                  << cart[i].getPrice() << "\t\t"
                  << "  " << cart[i].getQuantity() << "\t\t"
                  << " " << cart[i].getCost() << std::endl;

        total += cart[i].getCost();
    }
    std::cout << std::endl;
    std::cout << "Your total amount : ₹" << total << std::endl;
    itemCount = 0;
}

Store::~Store()
{
    delete[] item;
    delete[] cart;
}

int main()
{
    Store store;
    Item *item;
    std::cout << std::endl;
    for (int i = 0; i < 6; i++)
    {
        int code, quantity;
        float price;
        std::string name;
        code = Store::getCount() + 1;
        std::cout << "-----Item " << code << "-----" << std::endl;
        std::cout << "Enter item name: ";
        std::cin >> name;
        std::cout << "Enter item price: ";
        std::cin >> price;
        quantity = 25;
        item = new Item(code, price, name, quantity);
        store.setItem(*item);
        std::cout << std::endl;
    }
    system("clear");
    bool continueLoop = true;
    while (continueLoop)
    {
        int choice;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "-----Main Menu-----" << std::endl;
        std::cout << "1. Display Store" << std::endl;
        std::cout << "2. Add to Cart" << std::endl;
        std::cout << "3. Remove from Cart" << std::endl;
        std::cout << "4. Display Cart" << std::endl;
        std::cout << "5. Confirm Purchase" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            store.display();
            break;
        case 2:
        {
            int code, quantity;
            std::cout << "Enter item code: ";
            std::cin >> code;
            std::cout << "Enter quantity: ";
            std::cin >> quantity;
            store.addToCart(code, quantity);
            break;
        }
        case 3:
        {
            int code, quantity;
            std::cout << "Enter item code: ";
            std::cin >> code;
            std::cout << "Enter quantity: ";
            std::cin >> quantity;
            store.removeFromCart(code, quantity);
            break;
        }
        case 4:
            store.showCart();
            break;
        case 5:
            store.confirmPurchase();
            break;
        case 6:
            std::cout << "Thank you for using the program." << std::endl;
            continueLoop = false;
            break;
        default:
            std::cout << "Please provide a valid choice!" << std::endl;
            break;
        }
        std::cout << std::endl;
    }

    return 0;
};
