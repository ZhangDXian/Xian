//#include <iostream>
//using namespace std;
//
//class CPeople
//{
//public:
//    CPeople()
//    {
//        cout << "CPeople" << endl;
//    }
//};
////public:   父类怎样，自雷就怎么样
////protected 继承之后，父类的public 降级为protected
//class Cxiaoming : protected CPeople
//{
//public:
//    Cxiaoming()
//    {
//        cout << "Cxiaoming" << endl;
//    }
//};
//class Cxiaohua : public Cxiaoming
//{
//public:
//    Cxiaohua()
//    {
//        cout << "Cxiaohua" << endl;
//    }
//};
//int main()
//{
//    Cxiaoming xm;   //继承构造的顺序，先父类，再子类。
//    Cxiaohua xh;
//    system("pause");
//    return 0;
//}
