#include <iostream>
#include <thread>
#include <functional>
#include <unistd.h>
#include <mutex>
#include <queue>
#include <list>
#include <condition_variable>

using namespace std;

mutex mutex1;

// day09_01_1/1/2/3/4/5/6
/*

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
*/

// day09_01_7_1
/*
class Box
{

};

queue<Box*> q;

void init()
{
    for (int i = 0; i < 10; i++)
    {
        q.push(new Box());
    }
}

void move_out(string name)
{
    mutex1.lock();
    if (!q.empty())
    {
        usleep(1000 * 300);
        q.pop();
        cout << name << "搬走了一个盒子，剩余" << q.size() << endl;
    }
    mutex1.unlock();
}

void func1()
{
    while (1)
    {
        move_out("func1");
        usleep(1000 * 100);
    }
}

void func2()
{
    while (1)
    {
        move_out("func2");
        usleep(1000 * 50);
    }
}

int main()
{
    init();

    thread t1(func1);
    thread t2(func2);

    t1.join();
    t2.join();

    return 0;
}
*/

// day09_01_7_2
/*
class Box
{

};

class WorkTable
{
    queue<Box> q;
    mutex  m;

public:
    WorkTable()
    {
        cout << "执行工作台的构造函数" << endl;
        for (int i = 0; i < 10; i++)
        {
            q.push(Box());
        }
    }

    ~WorkTable()
    {
        cout << "执行工作台的析构函数" << endl;
    }

    void move_out(string name)
    {
        m.lock();
        if (!q.empty())
        {
            usleep(1000 * 500);
            q.pop();
            cout << name << " 搬走了一个盒子，剩余" << q.size() << endl;
        }
        m.unlock();
    }
};

class Hand
{
    WorkTable *wt;

public:
    Hand(WorkTable *wt)
        : wt(wt)
    {

    }

    ~Hand()
    {
        delete wt;
    }

    void move_box(string name, long time)
    {
        while (1)
        {
            wt->move_out(name);
            usleep(time);
        }
    }
};

int main()
{
    WorkTable wt;

    Hand left_hand(&wt);
    Hand right_hand(&wt);

    thread t1(bind(&Hand::move_box, &left_hand, "left", 1000 * 100));
    thread t2(bind(&Hand::move_box, &right_hand, "right", 1000 * 50));

    t1.join();
    t2.join();

    return 0;
}
*/

// day09_01_3/4
/*
void func()
{
    int count = 10;

    while (count > 0)
    {
        //lock_guard<mutex> lg(mutex1);
        unique_lock<mutex> ul(mutex1);
        cout << "thread_" << this_thread::get_id() << "...count = " << count << endl;
        count--;

        ul.unlock();
        usleep(1000 * 100);
    }
}

int main()
{
    thread t1(func);
    thread t2(func);

    t1.join();
    t2.join();

    return 0;
}
*/

// day09_01_7_5_1
/*
condition_variable cv;
mutex m;

void func1()
{
    for (int i = 0; i < 100; i++)
    {
        usleep(1000 * 1000);
        lock_guard<mutex> lg(m);
        cout << "func1 --- i = " << i << endl;
        if (i % 10 == 0)
        {
            cout << "func1:: 当前i能整除10，通知func2运行..." << endl;
            cv.notify_one();
        }
    }
}

void func2()
{
    for (int i = 0; i < 100; i++)
    {
        unique_lock<mutex> ul(m);
        cout << "func2 === i = " << i << endl;
        if (i % 5 == 0)
        {
            cout << "func2:: 当前i能整除5，处于等待..." << endl;
            cv.wait(ul);
        }
    }
}

int main()
{
    thread t1(func1);
    thread t2(func2);

    t1.join();
    t2.join();

    return 0;
}
*/

// day09_01_7_5_2
/*
class Box
{

};

queue<Box> q;

void init()
{
    for (int i = 0; i < 10; i++)
    {
        q.push(Box());
    }
}

void left_hand()
{
    while (1)
    {
        q.push(Box());
        cout << "左手臂往工作台放了一个盒子，数量：" << q.size() << endl;
        usleep(1000 * 1000);
    }
}

void right_hand()
{
    while (1)
    {
        if (!q.empty())
        {
            q.pop();
            cout << "右手臂从工作台搬走了一个盒子，数量还剩下：" << q.size() << endl;
        }
        usleep(1000 * 500);
    }
}

int main()
{
    thread t1(left_hand);
    thread t2(right_hand);

    t1.join();
    t2.join();

    return 0;
}
*/

// day09_01_7_5_3_a
/*
class Box
{

};

queue<Box> q;
condition_variable cv;
mutex m;

void left_hand()
{
    while (1)
    {
        usleep(1000 * 3000);
        lock_guard<mutex> lg(m);
        q.push(Box());
        cout << "左手臂往工作台放了一个盒子，数量：" << q.size() << endl;
        cv.notify_one();
    }
}

void right_hand()
{
    while (1)
    {
        unique_lock<mutex> ul(m);
        cv.wait(ul, []{
            cout << "wait cv" << endl;
            return !q.empty();
        });

        q.pop();
        cout << "右手臂从工作台搬走了一个盒子,数量还剩下：" << q.size() <<endl;
    }
}

int main()
{
    thread t1(left_hand);
    thread t2(right_hand);

    t1.join();
    t2.join();

    return 0;
}
*/

class Box
{

};

mutex _mutex;
condition_variable cv;

class WorkTable
{
    queue<Box*> _queue;

public:
    Box pop()
    {
        _queue.pop();
    }

    void push(Box *box)
    {
        _queue.push(box);
    }

    int size()
    {
        return _queue.size();
    }
};

class LeftHand
{
    WorkTable *work_table;

public:
    LeftHand(WorkTable *work_table)
        : work_table{work_table}
    {
        cout << "构建LeftHand对象" << endl;
    }

    ~LeftHand()
    {
        cout << "析构LeftHand对象" << endl;
    }

    void move_in(Box *box)
    {
        while (1)
        {
            usleep(1000 * 1000 * 5); // 5 seconds
            lock_guard<mutex> lg(_mutex);
            work_table->push(box);
            cout << "Left:: 盒子数量：" << work_table->size() << endl;
            cv.notify_one();
        }
    }
};

class RightHand
{
    WorkTable *work_table;
public:
    RightHand(WorkTable *work_table)
        : work_table{work_table}
    {
        cout << "构建RightHand对象" << endl;
    }

    ~RightHand()
    {
        cout << "析构RightHand对象" << endl;
    }

    void move_out()
    {
        while (1)
        {
            cout << endl;
            cout << "*****************************" << endl;
            cout << "Right :: 即将去搬走盒子！" << endl;

            unique_lock<mutex> ul(_mutex);
            cv.wait(ul, [&]{
                cout << "Right :: 正在检查工作台盒子数量..." << endl;
                return work_table->size() > 0;
            });

            cout << "Right :: 从工作台搬离盒子，盒子数量：" << work_table->size() << endl;
            work_table->pop();
        }
    }
};

int main()
{
    WorkTable wt;
    LeftHand left_hand(&wt);
    RightHand right_hand(&wt);
    Box box;

    thread t1(bind(&LeftHand::move_in, &left_hand, &box));
    thread t2(bind(&RightHand::move_out, &right_hand));

    t1.join();
    t2.join();

    return 0;
}