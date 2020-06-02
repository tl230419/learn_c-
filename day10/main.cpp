#include <iostream>
#include "config.h"
#include "test.h"
#include "test2.h"

int main()
{
    std::cout << "age = " << age << std::endl;
    int result = test::add(3, 4);
    std::cout << "result = " << result << std::endl;

    int result2 = test2::add(8, 4);
    std::cout << "result2 = " << result2 << std::endl;

    return 0;
}
