/*******************************************
 *
 * Author: Allen
 * Date: 2020-05-14
 *
 *******************************************/

#include <iostream>

namespace shenzhen
{
    std::string name = "����";
}

namespace wuhan
{
    std::string name = "����";
}

int main(int argc, char ** args)
{
    // day01_03_2
    /*
    std::cout << "����������"<< argc << std::endl;

    std::cout << "��һ��������"<< args[0] << std::endl;
    std::cout << "��һ��������"<< args[1] << std::endl;
    */

    /* day01_04_2
    int age;
    double price;

    age = 10;
    price = 20.3;

    int age1 = 20;
    int age2(30);
    int age3{21};
    */

    // day01_04_3
    /*
    const double pi {3.1415926};
    const int months_in_year{12};

    //pi = 2.5; // wrong
    */

    // day01_04_4
    /*
    double a = 20.0;
    int len1 = sizeof(a);
    std::cout << "len1:" << len1 << std::endl;
    int len2 = sizeof(int);
    std::cout << "len2:" << len2 << std::endl;
    */

    // day01_05_1
    /*
    std::cout << "Hello";
    std::cout << " world";

    std::cout << "Hello" << std::endl;
    std::cout << " world" << std::endl;

    std::cout << "Hello " << " World" << " , I love C++!"<< std::endl;
    */

    /* input
    std::cout << "�������������䣺" << std::endl;

    int age;
    std::cin >> age;

    std::cout << "�������䣺" << age << std::endl;
    */

    // day01_07_1
    std::cout << shenzhen::name << std::endl;

    return 0;
}