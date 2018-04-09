#include <iostream>

using namespace std;

class CStu
{
public:
    int a;
    CStu()
    {
        a = 12;
    }
    void Show() const   //不能修改数据成员
    {
        cout << "i am show!" << a << endl;
    }
    void Fun()
    {
        cout << "i am Fun" << endl;
    }
};

int main()
{
    const CStu stu; //常对象只能调用常函数
    stu.Show();
    stu.Fun();


    return 0;
}
