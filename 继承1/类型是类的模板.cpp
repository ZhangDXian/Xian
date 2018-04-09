#include <iostream>
using namespace std;

template<typename Q>
class CAA
{
public:
    int a;
};
template<typename T,typename Y>
class CFather
{
public:
    CFather(CAA<char> &a)
    {

    }
   void fun()
   {
       cout << "CFather" << endl;
   }

};
template<typename X,typename Z,typename W>
class CSon : public CFather<X,Z>
{
public:
    void fun()
    {
        cout << "CSon" << endl;
    }
};

int main()
{
    CAA<char> ca;
    CFather<int,CAA<char>>pf(ca);
}
