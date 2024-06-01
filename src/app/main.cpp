#include "rectangle.hpp"
#include <iostream>
#include <string>

int main()
{
    Rectangle rectangle{2.0, 3.0, std::string{"Rectangle"}};
    std::cout << "Area of " << rectangle.name() << " is " << rectangle.area()
              << std::endl;
    return 0;
}