#include <iostream>
#include <cstring>

using namespace std;

class CStu{
public:
    int a[4];

    CStu()
    {
        memset(a,0,16);
    }

    void Show()
    {
        for(int i = 0;i != 4;++i)
            cout << a[i] << endl;
    }

};

int main()
{
    CStu cst;
    cst.Show();
    return 0;
}
