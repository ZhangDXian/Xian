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
    int aa;     //���ݲ���
    CSon& Show()
    {
        cout << "class CSon\n";
        return (*this);
    }
};
//class CSonSon : public CSon
//{
//public:
//    int aa;     //���ݲ���
//    void Show()
//    {
//        cout << "class CSonSon\n";
//    }
//};


int main()
{
    CFather* fa = new CSon;
    fa->Show();    //��ͨ��ֻ�ܵ������ڸ���ĳ�Ա
//    CSon* soso = new CSonSon;
//    soso->Show();

    return 0;
}
