#include <iostream>
using namespace std;

class CFather
{
public:
    virtual CFather& Show()
    {
        cout << "Class CFather\n";
        return (*this);
    }
};

class CSon : public CFather
{
public:
    int aa;     //数据不虚
    CSon& Show()
    {
        cout << "class CSon\n";
        return (*this);
    }
};
//class CSonSon : public CSon
//{
//public:
//    int aa;     //数据不虚
//    void Show()
//    {
//        cout << "class CSonSon\n";
//    }
//};


int main()
{
    CFather* fa = new CSon;
    fa->Show();    //普通的只能调用属于父类的成员
//    CSon* soso = new CSonSon;
//    soso->Show();

    return 0;
}
