//#include <iostream>
//using namespace std;
//
//class CFather
//{
//private:
//    int b;
//public:
//    int a;
//    CFather()
//    {
//        a = 12;
//        b = 13;
//    }
//    void fun()
//    {
//        cout << "CFather" << endl;
//    }
//    friend void Show();
//};
//
//
//
//class CSon : public CFather
//{
//private:
//    int c;
//public:
//    int a;
//    CSon()
//    {
//        a = 10;
//        c = 100;
//    }
//    void fun()
//    {
//        cout << "CSon" << endl;
//    }
//};
//void Show()
//{
//    CSon son;
//    cout << son.c << endl;
//}
//
//int main()
//{
//    CSon son;
//    son.CFather::fun();
//    return 0;
//}
