//#include <iostream>
//using namespace std;
//
//class CPeople
//{
//private:
//    void fun1()
//    {
//    cout << "father private;" << endl;
//    }
//protected:
//    void fun2()
//    {
//        cout << "father protected" << endl;
//    }
//public:
//    void fun3()
//    {
//        cout << "father public" << endl;
//    }
//};
////public:   �������������׾���ô��
////protected �̳�֮�󣬸����public ����Ϊprotected
//class Cxiaoming : protected CPeople
//{
//public:
//    int a;
//    void fun4()
//    {
//       // fun1();
//    }
//};
//class Cxiaohua : public Cxiaoming
//{
//public:
//    void fun5()
//    {
//        fun3();
//    }
//};
//int main()
//{
//    Cxiaoming xm;
//    Cxiaohua xh;
//    xh.fun5();
//    //xm.fun3();
////    xm.fun2();
////    xm.fun1();
//    system("pause");
//    return 0;
//}
