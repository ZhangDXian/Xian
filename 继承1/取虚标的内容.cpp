//#include <iostream>
//using namespace std;
//
//class CFather
//{
//public:
//    virtual void Show()     //虚函数不能内联
//    {
//        cout << "Class CFather\n";
//    }
//};
//
//class CSon : public CFather
//{
//public:
//    virtual void fun()
//    {
//        cout << "fun" << endl;
//    }
//    void Show()
//    {
//        cout << "class CSon\n";
//    }
//};
////class CSonSon : public CSon
////{
////public:
////    int aa;     //数据不虚
////    void Show()
////    {
////        cout << "class CSonSon\n";
////    }
////};
//
//
//int main()
//{
//    CFather* fa = new CSon;
//      //普通的只能调用属于父类的成员
////    CSon* soso = new CSonSon;
////    soso->Show();
//    using p = void(*)();
//    ((p)*(int*)*(int*)fa)();
//    return 0;
//}
