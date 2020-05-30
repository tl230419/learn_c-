#include <iostream>

using namespace std;

// day08_01_2_1
/*
template<typename T>
T add(const T& t1, const T& t2)
{
    return t1 + t2;
}

template<typename T>
T add(const T& t1, const T& t2, const T& t3)
{
    return t1 + t2 + t3;
}

int main()
{
    int result1 = add(1, 2);
    int result2 = add(1, 2, 2);
    std::cout << "result1 = " << result1 << std::endl;
    std::cout << "result2 = " << result2 << std::endl;

    return 0;
}
*/

// day08_01_3_1
/*
#include <stdarg.h>

int add(int count, ...)
{
    va_list vl;
    va_start(vl, count);

    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += va_arg(vl, int);
    }
    va_end(vl);

    return sum;
}

int main()
{
    int result = add(3, 1, 2, 3);
    cout << "result = " << result << endl;

    return 0;
}
*/

// day08_01_3_1
/*
int add(initializer_list<int> il)
{
    int sum = 0;
    for (auto ptr = il.begin(); ptr != il.end(); ptr++)
    {
        sum += *ptr;
    }

    return sum;
}

int main()
{
    int result = add({10, 20, 30});
    cout << "result = " << result << endl;

    return 0;
}
*/

// day08_01_4_1
/*
template <typename ...Args>
int add(Args...args1)
{
    int a = sizeof...(args1);
    cout << "���ݽ����Ĳ����У�" << a << endl;
}

int main()
{
    add(2, 3, 4, "a", "b", "c");
    
    return 0;
}
*/

// day08_01_4_2
/*
int add()
{
    cout << "end" << endl;
    return 0;
}

template <typename T, typename ...Args>
int add(T t, Args...args)
{
    cout << "��ӡ�������ǣ�" << t << endl;

    t += add(args...);

    return t;
}

int main()
{
    cout << add(1, 2, 3, 4, 5) << endl;

    return 0;
}
*/

// day08_01_5
/*
class Stack
{
private:
    enum
    {
        MAX = 10
    };
    int top = 0;
    string items[MAX];

public:
    bool is_empty()
    {
        return top == 0;
    }

    bool is_full()
    {
        return top == MAX;
    }

    int push(string val)
    {
        if (is_full())
        {
            return -1;
        }

        items[top++] = val;
    }

    string pop()
    {
        if (is_empty())
        {
            return "";
        }

        return items[--top];
    }

    string operator[](int index)
    {
        if (is_empty() || index > --top)
        {
            cout << "����Ϊ�ջ򳬳�Խ��" << endl;
            return "";
        }

        return items[index];
    }
};

template <typename T> class StackT
{
private:
    enum
    {
        MAX = 10
    };
    int top = 0;
    T items[MAX];

public:
    bool is_empty()
    {
        return top == 0;
    }

    bool is_full()
    {
        return top == MAX;
    }

    int push(const T& val)
    {
        if (is_full())
        {
            return -1;
        }

        items[top++] = val;
    }

    T pop()
    {
        if (is_empty())
        {
            return NULL;
        }

        return items[--top];
    }

    T operator[](int index)
    {
        if (is_empty() || index > --top)
        {
            cout << "����Ϊ�ջ򳬳�Խ��" << endl;
            return "";
        }

        return items[index];
    }
};

int main()
{
    Stack s1;
    s1.push("2243");
    s1.push("fs");

    string val = s1.pop();
    cout << val << endl;

    StackT<int> s2;
    s2.push(1);
    s2.push(2);

    int val2 = s2.pop();
    cout << val2 << endl;

    StackT<float> s3;
    s3.push(1.9);
    s3.push(2.2);

    float val3 = s3.pop();
    cout << val3 << endl;

    return 0;
}
*/

// day08_02
/*
#include <deque>
#include <forward_list>
#include <list>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <set>
#include <numeric>
#include <algorithm>

using namespace std;

bool mysort(const string& a , const string& b)
{
    return a.size() < b.size();
}

int main()
{
    deque<int> deque;
    deque.push_back(10);
    deque.push_back(20);
    deque.push_back(30);

    cout << "��һ���ǣ�" << deque.front() << endl;
    cout << "���һ���ǣ�" << deque.back() << endl;
    cout << "���ȣ�" << deque.size() << endl;
    cout << deque[0] << " " << deque.at(1) << endl;

    deque.at(0) = 100;

    for (int i : deque)
    {
        cout << " --> " << i << endl;
    }

    // forward_list
    forward_list<int> flist{80, 70, 90};
    flist.push_front(100);
    flist.insert_after(flist.begin(), 35);
    cout << "��ӡ��" << endl;
    for (auto i = flist.begin(); i != flist.end(); i++)
    {
        cout << " --> " << *i << endl;
    }

    flist.remove(70);
    flist.front() = 10;
    *flist.begin() = 20;
    cout << "��һ��Ԫ���ǣ�" << flist.front() << endl;

    cout << "������ӡ��" << endl;
    flist.sort();
    for (auto i = flist.begin(); i != flist.end(); i++)
    {
        cout << " --> " << *i << endl;
    }

    // list
    list<int> list1{80, 70, 88};
    list1.push_front(10);
    list1.push_back(20);

    list1.remove(70);

    list1.front() = 10;
    cout << "��һ��Ԫ���ǣ�" << list1.front() << endl;
    *list1.end() = 20;
    cout << "���һ��Ԫ���ǣ�" << list1.back() << endl;

    cout << "list��ӡ��" << endl;
    for (auto i = list1.begin(); i != list1.end(); i++)
    {
        cout << " --> " << *i << endl;
    }

    // vector
    vector<int> s{88, 85, 90, 95, 77};
    cout << *s.begin() << endl;
    cout << *(s.begin() + 1) << endl;
    cout << *(s.end() - 1) << endl;

    cout << "vector��ӡ��" << endl;
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << " --> " << *i << endl;
    }

    // pair
    pair<string, int> p("����", 17);
    cout << p.first << p.second << endl;

    // map
    map<string, string> address_map;
    address_map.insert({"����", "�Ǻ���԰1��"});
    address_map.insert(make_pair("����", "�Ǻ���԰1��"));
    address_map.insert(pair<string, string>("����", "�Ǻ���԰1��"));

    address_map.insert({"����", "�Ǻ���԰2��"});
    cout << "map��ӡ��" << endl;
    for (auto i = address_map.begin(); i != address_map.end(); i++)
    {
        cout << (*i).first << " --> " << (*i).second << endl;
    }

    string address = address_map["����"];
    cout << address << endl;

    string addr2 = address_map.at("����");
    cout << addr2 << endl;

    cout << "ɾ����ӡ��" << address_map.size() << endl;
    for (auto i = address_map.begin(); i != address_map.end(); )
    {
        cout << (*i).first << " --> " << (*i).second << endl;
        if (i->first == "����")
        {
            address_map.erase(i++);
            cout << "remove ���� " << endl;
        }
        else
        {
            i++;
        }
    }

    cout << "��ӡ��" << endl;
    for (auto i = address_map.begin(); i != address_map.end(); i++)
    {
        cout << (*i).first << " --> " << (*i).second << endl;
    }

    cout << "clear all: " << endl;
    address_map.erase("����");
    address_map.clear();

    // set
    set<int> s1({ 3, 4, 5, 6, 3});
    cout << "set print:" << s1.size() << endl;
    for (auto p = s1.begin(); p != s1.end(); )
    {
        cout << *p << endl;
        if (*p == 4)
        {
            s1.erase(p++);
            cout << "remove 4" << endl;
        }
        else
        {
            p++;
        }
    }

    s1.clear();

    set<int> s11({3,4,5,6});

    // common
    int a = accumulate(s11.begin(), s11.end(), 0);
    cout << a << endl;

    int b = accumulate(s11.cbegin(), s11.cend(), 0);
    cout << b << endl;

    set<int> s111{1, 2, 3, 4, 5};
    vector<int> v1{1, 2, 3, 4, 5};
    bool flag = equal(s111.begin(), s111.end(), v1.begin());
    cout << "flag = " << flag << endl;

    // fill
    vector<int> scores {10,20,30,40,50,60,70};
    fill(scores.begin() ,scores.end() , 0 );
    for (int score :scores)
    {
        cout << "score = " << score <<endl;
    }

    int scores1[] {66, 77, 88, 99, 100};
    int size = sizeof(scores1) / sizeof(int);
    int scores2[size];
    copy(begin(scores1), end(scores1) , scores2);

    for (int i = 0 ; i < size; i++)
    {
        cout << i << " = " << scores2[i] << endl;
    }

    vector<int> scores3 {30, 20, 30, 40, 30, 60};
    replace(scores3.begin(), scores3.end(), 30, 100);
    for (int score : scores3)
    {
        cout << " ===> " <<score <<endl;
    }

    vector<string> scores4{"ab", "bc", "aa", "abc", "ac"};

    sort(scores4.begin(), scores4.end());

    for (string score : scores4)
    {
        cout << " ===> " << score <<endl;
    }

    // remove repeat element
    vector<int> stu_vector{ 100,90,88,75,90,88,90};

    sort(stu_vector.begin() , stu_vector.end());
    auto end = unique(stu_vector.begin() , stu_vector.end());
    for (int a : stu_vector)
    {
        cout << a << "\t";
    }
    cout << endl;
    stu_vector.erase(end , stu_vector.end());
    cout << "after erase:" << endl;
    for (int a : stu_vector)
    {
        cout << a << "\t";
    }
    cout << endl;

    for (int a : stu_vector)
    {
        cout << a << "\t";
    }
    cout << endl;
    cout << "vector�ĳ����ǣ�" << stu_vector.size() << endl;
    cout << "vector���±�4��Ԫ���ǣ�"<< stu_vector[4] << endl;
    cout << "vector���±�5��Ԫ���ǣ�"<< stu_vector[5] << endl;

    // self define sort function
    vector<string> vv{"ab", "bc", "aa", "abc", "ac"};
    sort(vv.begin(), vv.end(), mysort);
    stable_sort(vv.begin(), vv.end(), mysort);

    for (string ss : vv)
    {
        cout << "===>" << ss << endl;
    }

    return 0;
}
*/

// day08_03_1_2
/*
#include <functional>
using namespace std;

void print(int a, string b)
{
    cout << a << " = " << b << endl;
}

class Stu
{
public:
    static int run(string name, int age)
    {
        cout << age << " ... " << name << endl;
        return 0;
    }

    int run2(string name, int age)
    {
        cout << age << " run2... " << name << endl;
    }
};

int main()
{
    function<void (int, string)> f = print;
    f(3, "�°���");

    function<int (int, int)> f2 = [](int a, int b){
        return a + b;
    };
    cout << f2(1, 2) << endl;

    function<int(string, int)> f3 = Stu::run;
    f3("�°���", 55);

    function<int(Stu, string, int)> f4 = &Stu::run2;
    function<int(Stu&, string, int)> f5 = &Stu::run2;
    function<int(Stu*, string, int)> f6 = &Stu::run2;

    Stu s1;
    f4(s1, "�°���", 55);

    Stu s2;
    f5(s2, "�°���", 56);

    Stu s3;
    f6(&s3, "�°���", 57);

    return 0;
}
*/

#include <functional>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

class Stu
{
public:
    int run(string name, int age)
    {
        cout << name << " : " << age << endl;
        return 0;
    }
};

int main()
{
    auto p1 = bind(add, 3, 4);
    cout << "result = " << p1() << endl;

    function<int ()> p2 = bind(add, 5, 4);
    cout << "result2 = " << p2() << endl;

    Stu s;

    function<int ()> f = bind(&Stu::run, s, "����", 18);
    f();

    auto b = bind(&Stu::run, s, "����", 18);
    b();

    auto c = bind(&Stu::run, s, placeholders::_1, 18);
    c("����");

    Stu s2;
    function<int (string)> d = bind(&Stu::run, s2, placeholders::_1, 18);
    d("����");

    return 0;
}