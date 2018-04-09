//#include <iostream>
//using namespace std;
//
//class CFather
//{
//public:
//    int a;
//    virtual void fun()
//    {
//
//    }
//};
//
//class CSon : public CFather
//{
//public:
//    int b;
//    void fun()
//    {
//
//    }
//};
//
//class COther
//{
//public:
//    double f;
//};
//
//int main()
//{
////    CFather* p;
////    CSon* s;
////    COther* o;
////    const CFather* p;
////    CSon* so;
////
////    so = (CSon*)p;
//    CFather* p;
//    CSon* s;
//    COther* o;
//    p = dynamic_cast<CFather*>(s);
//    s = dynamic_cast<CSon*>(p);
//    //CFather* p1 = const_cast<CFather*>(p);
//    //p = (CFather*)s;
//    //o = static_cast<COther*>(p);
//    o = reinterpret_cast<COther*>(s);
//    return 0;
//}
