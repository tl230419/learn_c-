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
    cout << "传递进来的参数有：" << a << endl;
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
    cout << "打印的数字是：" << t << endl;

    t += add(args...);

    return t;
}

int main()
{
    cout << add(1, 2, 3, 4, 5) << endl;

    return 0;
}
*/

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
            cout << "容器为空或超出越界" << endl;
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
            cout << "容器为空或超出越界" << endl;
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