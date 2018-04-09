#include <iostream>
#include <cstring>

using namespace std;

class CStu
{
public:
    int* a;
    CStu()
    {
        a = new int[2];
        a[0] = 12;
        a[1] =13;
    }
    CStu(const CStu &b)
    {
        //this->a = b.a;
        this->a = new int[2];
        //this->a[0] = b.a[0];
        //this->a[1] = b.a[1];
        memcpy(this->a,b.a,8);

    }

    ~CStu()
    {
        delete[] a;
    }
};

int main()
{
    {
        CStu tt;
        cout << tt.a[0] << " " << tt.a[1] << endl;

        CStu st = tt;
        cout << st.a[0] << " " << st.a[1] << endl;

    }
    system("pause");
    return 0;
}
