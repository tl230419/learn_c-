#include <iostream>

int main(int argc, char ** argv)
{
    // day03_01_2
    /*
    int age = 88;
    int *p = &age;

    std::cout << "ָ��ĵ�ַ�ǣ�" << &p << std::endl;
    std::cout << "ָ��洢���ǣ�" << *p << std::endl;
    std::cout << "ָ���С��" << sizeof(p) << std::endl;
    std::cout << "age��С��" << sizeof(age) << std::endl;
    */

    // day03_01_3
    /*
    int score{100};
    int *score_ptr{&score};
    std::cout << *score_ptr << std::endl;
    *score_ptr = 200;
    std::cout << *score_ptr << std::endl;
    std::cout << score << std::endl;
    */

    // day03_01_4_1/2
    /*
    int *int_ptr{nullptr};

    int_ptr = new int;
    std::cout << *int_ptr << std::endl;

    *int_ptr = 100;
    std::cout << *int_ptr << std::endl;

    delete int_ptr;
    */

    // day03_01_4_3
    int *array_ptr{nullptr};
    int size{};

    std::cout << "�������������С�ǣ�" << std::endl;
    std::cin >> size;

    array_ptr = new int[size];
    for (int i = 0; i < size; i++)
    {
        array_ptr[i] = i;
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << array_ptr[i] << " " << std::endl;
    }

    delete array_ptr;

    return 0;
}