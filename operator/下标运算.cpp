//#include <iostream>
//
//using namespace std;
//
//class CStu
//{
//public:
//    int a;
//    int b;
//    double d;
//
//    int nErr = -1;
//    CStu()
//    {
//        a = 12;
//        b = 23;
//        d = 45.0;
//    }
//    void* operator [] (int n)
//    {
//        switch (n)
//        {
//        case 0:
//            return &a;
//        case 1:
//            return &b;
//        case 2:
//            return &d;
//        }
//        return &nErr;
//    }
//};
//
//
//int main()
//{
//    CStu st;
//    cout << *(double *)st[2];
////    *(st[1]) = 14;
////    cout << *st[1];
//    system("pause");
//    return 0;
//}
