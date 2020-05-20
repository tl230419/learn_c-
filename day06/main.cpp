#include <iostream>

/*
class Father
{
public:
    void show()
    {
        std::cout << "father show" << std::endl;
    }
};

class Children : public Father
{
public:
    void show()
    {
        std::cout << "children show" << std::endl;
    }
};

int main()
{
    Father f = Children();
    f.show();

    return 0;
}
*/

// day06_01_3_1
/*
using namespace std;

class WashMachine
{
public:
    virtual void wash()
    {
        cout << "洗衣机在洗衣服" << endl;
    }
};

class SmartWashMachine : public WashMachine
{
public:
    virtual  void wash()
    {
        cout << "智能洗衣机在洗衣服" << endl;
    }
};

int main()
{
    WashMachine *w2 = new SmartWashMachine();
    w2->wash();

    return 0;
}
*/

// day06_01_3_1
/*
class Person
{
public:
    std::string name = "无名氏";
    virtual void eat()
    {
        std::cout << "Person eat." << std::endl;
    }

    virtual void sleep()
    {

    }
};

class Student: public Person
{
public:
    Student(std::string name, std::string school)
        : name(name)
        , school(school)
    {

    }

    virtual void eat()
    {
        std::cout << "Student eat." << std::endl;
    }

    virtual void read()
    {

    }

public:
    std::string name;
    std::string school;
};

int main()
{
    Student stu("lisi", "武汉大学");
    Person *p = &stu;
    p->eat();

    return 0;
}
*/

// day06_01_3_1
/*
using namespace std;

class father
{
public:
    virtual father()
    {
        cout <<"父亲构造函数~！~" << endl;
    }
};

int  main()
{
    father f ;
    return 0 ;
}
*/

// day06_01_3_3
/*
using namespace std;

class father
{

public:
    virtual ~father()
    {
        cout << "执行父类析构函数" << endl;
    }
};

// day06_01_3_4
/*
class son : public father
{
    ~son()
    {
        cout << "执行子类析构函数" << endl;
    }
};

int main()
{
    father *f = new son();
    delete f;

    return 0 ;
}
*/

// day06_01_4
/*
using namespace std;

class Father
{
public:
    virtual void run()
    {
        cout << "父亲在跑步" << endl;
    }
};

class Son: public Father
{
public:
    virtual void run() override
    {
        cout << "儿子在跑步" << endl;
    }
};

int main()
{
    Father *f = new Son();
    f->run();

    return 0;
}
*/

// day06_01_5_1
/*
class Person final
{
    Person()
    {

    }
};

class Student : public Person
{

};
*/

// day06_01_5_2
/*
class Person
{
    virtual void run() final
    {

    }
};

class Student : public Person
{
    void run()
    {

    }
};
*/


// day06_01_6_1
/*
#include <string>

using namespace std;

class Stu
{
private:
    string name;
    int age;

public:
    Stu(string name, int age)
        : name(name)
        , age(age)
    {
        cout << "执行stu的构造函数" << endl;
    }

    Stu(Stu & s) =delete;

    ~Stu()
    {
        cout << "执行stu的析构函数" << endl;
    }
};

int main()
{
    Stu s("张三",18) ;

    Stu s1 = s;

    return 0 ;
}
*/

// day06_01_6_2
/*
#include <string>

using namespace std;

class Stu
{
private:
    string name;
    int age;

public:
    Stu() = default;

    Stu(string name, int age)
        : name(name)
        , age(age)
    {
        cout << "执行stu的构造函数" << endl;
    }

    ~Stu()
    {
        cout << "执行stu的析构函数" << endl;
    }
};

int main()
{
    Stu s("张三",18);

    return 0 ;
}
*/

// day06_01_6_7
/*
using namespace std;

class WashMachine
{
public:
    virtual void wash() = 0;
};

class HaierMachine:public WashMachine
{
public :
    virtual void wash()
    {
        cout << "海尔牌洗衣机在洗衣服" << endl;
    }
};

class LittleSwanMachine : public WashMachine
{
public :
    virtual void wash()
    {
        cout << "小天鹅洗衣机在洗衣服" << endl;
    }
};

int main()
{
    //WashMachine w;
    WashMachine *w1 = new HaierMachine();
    w1->wash();
    WashMachine *w2 = new LittleSwanMachine();
    w2->wash();

    return 0 ;
}
*/

class Person
{
    Person() =default;
    virtual ~Person() =default;

    virtual void eat() = 0;
    virtual void work() = 0;
    //...
};

int main()
{
    return 0;
}