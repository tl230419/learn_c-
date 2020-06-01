#include <iostream>
#include "config.h"
#include "test.h"

int main()
{
    std::cout << "age = " << age << std::endl;
    int result = test::add(3, 4);
    std::cout << "result = " << result << std::endl;

    return 0;
}
