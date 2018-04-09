//#include <iostream>
//using namespace std;
//
//class CFather
//{
//public:
//     ~CFather()
//    {
//        cout << "CFather" << endl;
//    }
//};
//
//class CSon : public CFather
//{
//public:
//     ~CSon()
//    {
//        cout << "CSon" << endl;
//    };
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
//class Cxiaoming
//{
//public:
//    ~Cxiaoming()
//    {
//        cout << "Cxiaoming" << endl;
//    };
//};
//
//
//int main()
//{
//    CFather* fa = new CSon;
//      //普通的只能调用属于父类的成员
////    CSon* soso = new CSonSon;
////    soso->Show();
//
//    delete (Cxiaoming*)fa;
//    return 0;
//}
