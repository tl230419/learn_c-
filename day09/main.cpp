#include <iostream>
#include <thread>
#include <functional>
#include <unistd.h>
#include <mutex>

using namespace std;

mutex mutex1;

void show()
{
    for (int i = 0; i < 10; i++)
    {
        cout << __func__ << " = " << i << endl;
        this_thread::sleep_for(chrono::seconds(1));
        //usleep(1000 * 10000); // ms
        if (i == 3)
        {
            cout << "函数返回，线程终止。" << endl;
            return;
        }
    }
}

class Stu
{
public:
    string name;
    int age;

    Stu(const string& name, int age)
        : name(name)
        , age(age)
    {
        cout << "执行了构造函数~" << name << " = " << age << endl;
    }
};

void constructor(string name, int age)
{
    cout << "执行构造学生的工作~1" << endl;
    Stu s(name, age);
}

void func()
{
    int count = 10;
    while (count > 0)
    {
        mutex1.lock();
        cout << "thread_" << this_thread::get_id() << "...count = " << count << endl;
        count--;
        mutex1.unlock();
        usleep(1000 * 500);
    }
}

int main()
{
    // day09_01_1/2/3
//    thread t(show);
//    //t.join();
//    t.detach();
//    std::cout << "执行了main函数" << std::endl;

    // day09_01_4/5
//    thread t1(bind(constructor, "张三", 16));
//    cout << this_thread::get_id() << endl;
//    cout << t1.get_id() << endl;

    thread t1(func);
    thread t2(func);

    t1.join();
    t2.join();
    
    return 0;
}
