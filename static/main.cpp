#include <iostream>

using namespace std;

class CStu
{
public:
    static int b;
    CStu()
    {
        b++;
    }
};
int CStu::b = 0;
int main()
{
    CStu st[5];
    cout << CStu::b << endl;

    system("pause");
    return 0;
}
