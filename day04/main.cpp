#include <iostream>
#include <string>

// day04_01
/*
class Student
{
private:
    std::string name;
    int age;

public:
    void read()
    {
        std::cout << "ѧ���ڿ���" << std::endl;
    }
};

int main()
{
    Student stu1;
    Student stu2;

    Student *s3 = new Student;
    s3->read();

    (*s3).read();

    return 0;
}
*/

// day04_02_3
/*
class Student
{
public:
    std::string name;
    std::string *address = nullptr;

    Student(std::string name, std::string *address)
        : name(name)
        , address(address)
    {
        std::cout << "ִ�й��캯��, address: " << address << std::endl;
    }

    Student(const Student& s)
    {
        std::cout << "�����˿������캯��" << std::endl;
        name = s.name;
//        address = s.address;

        // Deep copy
        if (address == nullptr)
        {
            std::cout << "���" << std::endl;
            address = new std::string();
            *address = *s.address;
        }
    }

    ~Student()
    {
        std::cout << "��������������" << std::endl;
        if (address != nullptr)
        {
            delete address;
            address = nullptr;
        }
    }
};

int main(int argc, char** argv)
{
    std::string address = "����";
    Student s1("����", &address);

    Student s2 = s1;
    std::cout << s2.name << " : " << *s2.address << std::endl;

    *s1.address = "����";
    std::cout << s2.name << " : " << *s2.address << std::endl;

    return 0;
}
*/

// day04_02_3_5_2/3
/*
class Student
{
public:
    std::string name;
    int age;

    Student(std::string name, int age)
        : name(name)
        , age(age)
    {
    }
};

void print_stu(Student s)
{
    std::cout << s.name << " : " << s.age << std::endl;
}

Student create_stu()
{
    return Student("����", 18);
}

int main(int arga, char** argv)
{
    // 2
//    Student stu1("����", 18);
//    print_stu(stu1);

    // 3
    Student stu = create_stu();
    std::cout << stu.name << " : " << stu.age << std::endl;

    return 0;
}
*/

// day04_02_7_2
/*
class Student
{
public:
    int *age;

    Student()
        : age(new int(18))
    {
        std::cout << "ִ�й��캯����" << std::endl;
    }

    Student(const Student& s)
        : age(new int(*s.age))
    {
        std::cout << "ִ�п������캯����" << std::endl;
        delete age;
    }

    Student(Student&& s)
            : age(s.age)
    {
        std::cout << "ִ���ƶ����캯����" << std::endl;
        s.age = nullptr;
    }

    ~Student()
    {
        std::cout << "ִ������������" << std::endl;
        delete age;
    }
};

Student get_stu()
{
    Student s;
    std::cout << "get_stu = " << __func__ << " : " << s.age << std::endl;
    return s;
}

int main(int argc, char** argv)
{
    Student stu = get_stu();

    return 0;
}
*/

// day04_02_7_3
/*
class Student
{
public:
    std::string name;
    int age;

    Student()
    {

    }
};

int main(int argc, char** argv)
{
    int a = 3;
    int &b = a;
    int &&c = 3;
    int &&d = std::move(b);

    Student stu1;
    Student stu2 = stu1;

    Student stu3 = std::move(stu1);
    Student stu4(std::move(stu1));
}
*/

// day04_03_1
/*
class Student
{
public:
    std::string name;
    int age;

    Student(std::string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    Student& get_stu()
    {
        return *this;
    }
};

int main(int argc, char** argv)
{
    Student s1("����", 18);
    Student &s2 = s1.get_stu();

    return 0;
}
*/

// day04_03_2/3
/*
class Student
{
public:
    std::string name;
    int age;

public:
    Student(std::string name, int age)
        : name(name)
        , age(age)
    {

    }

    void print_student() const
    {
        //age = 10;
        std::cout << name << " " << age << std::endl;
    }

    void run()
    {
        std::cout << age << "��" << name << "���ܲ�" << std::endl;
    }
};

int main(int argc, char** argv)
{
    const Student s1("zhangdan", 18);

    std::cout << s1.name << std::endl;
//    s1.name = "����";

    return 0;
}
*/

// day04_03_4
/*
class Student
{
public:
    int age;
    std::string name;
    static std::string school;

public:
    static std::string get_school()
    {
        return school;
    }
};

std::string Student::school = "������ѧ";

int main(int argc, char** argv)
{
    Student s;
    s.name = "����";
    s.age = 18;

    std::cout << s.get_school() << std::endl;

    std::cout << s.school << std::endl;

    return 0;
}
*/

// day04_03_5
/*
class Car
{
private:
    std::string color{"��ɫ"};
    friend void show_color(Car c);
};

void show_color(Car c)
{
    std::cout << c.color << std::endl;
}

int main(int argc, char** argv)
{
    Car c;

    show_color(c);

    return 0;
}
*/

// day04_03_6
/*
class Car
{
private:
    std::string color{"��ɫ"};
    friend class SSSS;

public:
    std::string get_color()
    {
        return color;
    }
};

class SSSS
{
public:
    void modify_car(Car &mycar)
    {
        mycar.color = "��ɫ";
    }
};

int main(int argc, char** argv)
{
    SSSS s;
    Car c;

    s.modify_car(c);
    std::cout << c.get_color() << std::endl;

    return 0;
}
*/

