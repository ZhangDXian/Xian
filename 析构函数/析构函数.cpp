#include <iostream>
using namespace std;


class CStu
{
public:
    int nAge;
    CStu()
    {
        cout << "构造函数" << endl;
    }

    ~CStu()
    {
        cout << "析构函数" << endl;
    }
};
int main()
{
    //CStu stu;
    CStu* stu = (CStu*)malloc(sizeof(CStu));
    //delete stu;
    CStu();
    system("pause");
    return 0;
}
