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
    void Show() const   //�����޸����ݳ�Ա
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
    const CStu stu; //������ֻ�ܵ��ó�����
    stu.Show();
    stu.Fun();


    return 0;
}
