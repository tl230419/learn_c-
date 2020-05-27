#include <iostream>

// day07_02_1_1
/*
enum class Week
{
    MON,
    TUS,
    WEN,
    THU,
    FRI,
    STU,
    SUN
};

int main()
{
    int val = (int)Week::TUS;
    std::cout << val << std::endl;

    return 0;
}
*/

// day07_02_1_2
/*
enum traffic_light
{
    red,
    yellow,
    green
};

//enum
//{
//    red,
//    yellow,
//    green
//};

enum
{
    Red = 10,
    Yellow = 20,
    Green = 30
};

int main()
{
    int a = traffic_light::red;
    std::cout << a << std::endl;

    int b = ::Red;
    std::cout << b << std::endl;
}
*/

/*
#include <vector>
#include <string>

using namespace std;

enum Gender
{
    MALE,
    FEMALE
};

class Teacher
{
public:
    string name;
    Gender gender;

    Teacher(string name, Gender gender)
        : name(name)
        , gender(gender)
    {

    }
};

int main()
{
    Teacher t1("张三", Gender::MALE);
    Teacher t2("李丽丽", Gender::FEMALE);
    Teacher t3("李四", Gender::MALE);

    vector<Teacher> v;
    v.push_back(t1);
    v.push_back(t2);
    v.push_back(t3);

    for (Teacher t : v)
    {
        switch (t.gender)
        {
            case Gender::MALE:
                cout << "男老师" << endl;
                break;
            case Gender::FEMALE:
                cout << "女老师" << endl;
                break;
            default:
                cout << "性别错误" << endl;
                break;
        }
    }

    return 0;
}
*/

// day07_03
/*
class Stu
{
public:
    Stu(Stu && s) noexcept
    {

    }

    void operator=(Stu && s) noexcept
    {

    }
};
*/

// day07_04_1_1
/*
using namespace std;

int main()
{
    bool flag = false;
    cout << "flag = " << flag << endl;

    cout << "flag = " << flag << " after add boolalpha flag = " << boolalpha << flag << endl;

    return 0;
}
*/

// day07_04_1_2
/*
using namespace std;

int main()
{
    cout << "十进制：" << dec << 9 << endl;
    cout << "八进制：" << oct << 9 << endl;
    cout << "十六进制：" << hex << 9 << endl;

    cout << showbase;
    cout << "十进制：" << dec << 9 << endl;
    cout << "八进制：" << oct << 9 << endl;
    cout << "十六进制：" << hex << 9 << endl;
    cout << noshowbase;

    return 0;
}
*/

// day07_04_1
/*
#include <iomanip>

using namespace std;

int main()
{
    double a = 10.12345678901234;
    cout.precision(3);
    cout << "a = " << a << endl;

    cout << setprecision(5) << "a = " << a << endl;

    float f = 10.00;
    cout.precision(4);
    cout << showpoint << "f = " << f << noshowpoint << endl;

    cin >> noskipws;
    char c;
    cout << "请输入字符：" << endl;
    while (cin >> c)
    {
        cout << c;
    }
    cin >> skipws;

    return 0;
}
*/

// day07_04_2_1
/*
#include <sstream>

using namespace std;

int main()
{
    string str = "我是中国人 我爱中国";
    istringstream stream(str);
    string s;
    while (stream >> s)
    {
        cout << s << endl;
    }

    return 0;
}
*/

/*
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int a = 55;
    double b = 65.123;
    string str = "";

    ostringstream oss;
    oss << a << "---" << endl;

    str = oss.str();
    cout << str << endl;

    return 0;
}
*/

// day07_04_3_a
/*
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    fstream file{"../test.txt", ios::in};
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "文件无法正常打开！" << endl;
    }

    return 0;
}
*/

// day07_04_3_1_2
/*
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    fstream matrix_file{"../matrix.txt", ios_base::in};
    string line;

    if (!matrix_file.is_open())
    {
        cout << "打开文件失败！" << endl;
        return 1;
    }

    stringstream ss;
    float number;
    vector<vector<float>> matrix_vector;
    vector<float> row_vector;

    while (getline(matrix_file, line))
    {
        cout << "line = " << line << endl;
        row_vector.clear();
        ss.clear();
        ss.str(line);
        while (ss >> number)
        {
            if (ss.peek() == ',' || ss.peek() == ' ')
            {
                ss.ignore();
            }
            row_vector.push_back(number);
        }
        matrix_vector.push_back(row_vector);
    }
    matrix_file.close();

    for (int i = 0; i < matrix_vector.size(); i++)
    {
        for (int j = 0; j < matrix_vector[i].size(); j++)
        {
            cout << matrix_vector[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
*/

// day07_04_3_2_a
/*
#include <ostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file("../test2.txt", ios::app);

    if (!file.is_open())
    {
        cout << "文件打开失败！" << endl;
        return 1;
    }

    cout << "正常打开文件" << endl;
    file << ", hi c++";

    file << endl;
    file.close();

    return 0;
}
*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    vector<vector<float>> matrix_vector
    {
            {1, 6, 2, 10.5},
            {11, 15.2, 2, 21},
            {3, 9, 1, 7.5}
    };

    fstream matrix_file("../matrix.txt", ios::app);
    if (!matrix_file.is_open())
    {
        cout << "文件打开失败！" << endl;
        return 1;
    }

    for (int i = 0; i < matrix_vector.size(); i++)
    {
        for (int j = 0; j < matrix_vector[i].size(); j++)
        {
            matrix_file << matrix_vector[i][j];
            if (j != matrix_vector[i].size() - 1)
            {
                matrix_file << ",";
            }
        }
        matrix_file << endl;
    }
    matrix_file.close();
    cout << "文件写入完毕" << endl;

    return 0;
}