///**
// *文件名：
// *描述：
// *作者：
// *时间：
// *版权：
// */
//#include <iostream>
//
//using namespace std;
//
//class CStu
//{
//private:
//    int nAge;
//public:
//    CStu()
//    {
//        nAge = 12;
//    }
//    int operator+(int a)    //this 类 + a
//    {
//        return (nAge + a);
//    }
//    int operator!()
//    {
//        return (!nAge);
//    }
//    friend ostream& operator << (ostream& os,const CStu& st);
//};
//ostream& operator << (ostream& os,const CStu& st)
//{
//    os << st.nAge;
//    return os;
//}
////int operator-(CStu& st)
////{
////    return (-st.nAge);
////}
//int main()
//{
//    CStu st;
//    cout << st << st;
//
//    system("pause");
//    return 0;
//}
