#include <iostream>

// day05_01_3
/*
class Student
{
public:
    int age;

    Student(int age)
        : age(age)
    {

    }

//    Student operator+ (Student& s)
//    {
//        Student temp(this->age + s.age);
//        return temp;
//    }
};

Student operator+ (Student& s, Student &ss)
{
    Student temp(s.age + ss.age);
    return temp;
}

int main()
{
    Student s1(10);
    Student s2(20);

    Student s3 = s1 + s2;
    std::cout << "s3.age = " << s3.age << std::endl;

    return 0;
}
*/

// day0
/*
class Student
{
public:
    std::string name{"zhangsan"};

public:
    Student(std::string name)
    {
        this->name = name;
    }
};

std::ostream& operator<< (std::ostream& o, Student &s1)
{
    o << s1.name;
    return o;
}

std::istream& operator>> (std::istream& in, Student &s1)
{
    in >> s1.name;
    return in;
}

int main()
{
    Student s1("����");
    std::cout << s1 << std::endl;

    std::cout << "������ѧ�������ƣ�" << std::endl;
    std::cin >> s1;
    std::cout << s1 << std::endl;

    return 0;
}
*/

// day05_01_6
/*
class Student
{
public:
    std::string name;
    int age;
    int *d;

public:
    Student(std::string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    Student& operator=(const Student& stu)
    {
        std::cout << "ִ�п�����ֵ����" << std::endl;
        d = new int();
        *d = *stu.d;
    }

    Student& operator=(const Student&& stu)
    {
        std::cout << "ִ���ƶ���ֵ����" << std::endl;
        d = stu.d;
        //stu.d = nullptr;

        return *this;
    }
};

int main()
{
    Student stu1("����", 18);
    stu1.d = new int();
    *stu1.d = 100;

//    Student stu2;
//
//    stu2 = stu1;

//    Student stu2 = std::move(stu1);
}
*/

/*
class Calc
{
public:
    int operator()(int val)
    {
        return val < 0 ? -val : val;
    }
};

int main()
{
    Calc c;
    int value = c(-10);
    std::cout << value << std::endl;

    return 0;
}
*/

/*
#include <functional>
int main()
{
    plus<int> p;
    int a = p(3, 5);

    negate<int> n;
    std::cout << n(-10) << std::endl;

    return 0;
}
*/

// day05_02_2/3
/*
int main()
{
    auto f = [](int a, int b)->int{ return a + b; };

    int result = f(3, 4);
    std::cout << "result = " << result << std::endl;

    auto ret = [](int a, int b)->int{ return a + b; }(3, 4);

    std::cout << "ret = " << ret << std::endl;

    int a = 3;
    int b = 5;
    auto f1 = [a, b]{ return a + b; };
    std::cout << "f1 = " << f1() << std::endl;

    auto f2 = [&a, &b]
    {
        a = 30;
        return a + b;
    };
    std::cout << "f2 = " << f2() << std::endl;
    std::cout << "a = " << a << std::endl;

    return 0;
}
*/

// day05_02_4
/*
#include <vector>

int get_cout(std::vector<int> scores)
{
    int result = 0;
    for (int s : scores)
    {
        result += s;
    }

    return result;
}

int main()
{
    std::vector<int> scores{ 80, 90, 75, 99, 73, 23};

    int result = get_cout(scores);
    std::cout << "sum = " << result << std::endl;

    int result2 = [&]
    {
        int result = 0;
        for (int s : scores)
        {
            result += s;
        }

        return result;
    }();

    std::cout << "sum2 = " << result2 << std::endl;

    return 0;
}
*/

// day05_03_4_1/2
/*
class Person
{
public:
    Person()
    {
        std::cout << "�����˸��๹�캯��" << std::endl;
    }

    ~Person()
    {
        std::cout << "�����˸�����������" << std::endl;
    }
};

class A
{
public:
    A()
    {
        std::cout << "����A�Ĺ��캯��" << std::endl;
    }

    ~A()
    {
        std::cout << "����A����������" << std::endl;
    }
};

class Student: public Person
{
public:
    Student()
    {
        std::cout << "���������๹�캯��" << std::endl;
    }

    ~Student()
    {
        std::cout << "������������������" << std::endl;
    }

public:
    A a;
};



int main()
{
    Student s1;

    return 0;
}
*/

// day05_03_4_3
/*
class Person
{
private:
    int age;
    std::string name ;

public :
    Person(int age , std::string name)
    {
        std::cout << "�����˸��๹�캯��" << std::endl;
        this->age = age ;
        this->name = name;
    }
};

class Student: public Person
{
public:
    Student(int age, std::string name): Person(age, name)
    {
        std::cout << "�����������๹�캯��" << std::endl;
    }
};

int main()
{
    Student s1(18 , "zs");
    return 0 ;
}
*/

// day05_03_4_4_1
/*
class stu
{
public:
    const std::string name; //�����������޸�ֵ�����Բ������ڹ�������ʹ��  = ��ֵ
    int age;

    stu(std::string name , int age)
        : name(name)
        , age(age)
    {
        std::cout << "ִ�й��캯��" << std::endl;
    }
};

int main()
{

    stu s1("����" , 88);
    std::cout << s1.name << " = " << s1.age << std::endl;

    return 0 ;
}
*/

// day05_03_4_4_2
/*
using namespace std;

class A
{
public:
    int number;

    A(int number)
        : number(number)
    {
        cout << "ִ����A�Ĺ��캯��" <<endl;
    }
};

class stu
{
public:
    A a;

    stu()
        : a(9)
    {

        cout << "ִ����stu�Ĺ��캯��" <<endl;
    }
};

int main()
{
    stu s;
    return 0;
*/

// day05_03_5
/*
class WashMachine
{
public:
    void wash()
    {
        std::cout << "ϴ�»���ϴ�·�" << std::endl;
    }
};


class SmartWashMachine : public WashMachine
{
public:
    void wash()
    {
        std::cout << "����ϴ�»���ϴ�·�" << std::endl;
        std::cout << "��ʼ���ϴ��Һ~~" << std::endl;

        WashMachine::wash();
    }
};

int main()
{
    SmartWashMachine s;
    s.wash();

    return 0 ;
}
 */

// day05_03_6_0
/*
using namespace std;

class Father
{
public:
    void makeMoeny()
    {
        std::cout << "׬Ǯ" << std::endl;
    }
};
class Mother
{
public:
    void makeHomeWork()
    {
        std::cout << "�������" << std::endl;
    }
};

class Son: public Father, public Mother
{

};

int main()
{
    Son s ;
    s.makeMoeny();
    s.makeHomeWork();

    return 0 ;
}
*/

// day05_06_1
/*
using namespace std;

class Father
{
public:
    string name;

public:
    Father(string name)
        : name(name)
    {
        std::cout << "ִ�и��׹��캯��" << std::endl;
    }
};

class Mother
{
    int age;

public:
    Mother(int age)
        : age(age)
    {
        std::cout << "ִ��ĸ�׹��캯��" << std::endl;
    }

};

class Son: public Father, public Mother
{
public:
    Son(string name, int age): Father(name), Mother(age)
    {
        cout << "ִ�к��ӹ��캯��" <<endl;
    }
};

int main()
{
    Son s("������" ,38);

    return 0 ;
}
*/

// day05_03_7
class father;

class son
{
public:
    father &f1;
    father *f2;

    son(father &f1 , father *f2) :f1(f1), f2(f2)
    {

    }
};

class father
{

};

int main()
{
    father f1;
    father f2;

    son s(f1 ,&f2);

    return 0 ;
}