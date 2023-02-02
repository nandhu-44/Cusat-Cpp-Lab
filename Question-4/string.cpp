#include <iostream>

class Strings
{
private:
    char *str;
    int length;

public:
    void getData(char *s)
    {
        str = s;
    }
    auto getLength()
    {
        return length;
    }
    friend Strings concatenate(Strings, Strings);
    friend bool compare(Strings, Strings);
    ~Strings()
    {
        delete[] str;
    }
};

Strings concatenate(Strings s1, Strings s2)
{
    return s1.str + s2.str;
}

bool compare(Strings s1, Strings s2)
{
    return s1.str == s2.str;
}

int main()
{
    Strings s1;
    s1.getData('Hello');
    std::cout << s1.getLength() << std::endl;
}
