//#include <iostream>
//
//using namespace std;
//
//class CStu
//{
//public:
//    int nAge;
//    CStu()
//    {
//        nAge = 12;
//    }
//    int operator ++ ()
//    {
//        nAge += 1;
//        return nAge;
//    }
//    int operator -- ()
//    {
//        nAge -= 1;
//        return nAge;
//    }
//};
//int operator ++ (CStu& st,int n)        //±ê¼Ç
//{
//    int temp = st.nAge;
//    st.nAge += 1;
//    return temp;
//}
//
////int operator ++ (CStu& st)
////{
////    st.nAge += 1;
////    return st.nAge;
////}
//
//int main()
//{
//    CStu st;
//    cout << ++st;
//    cout << --st;
//
//    cout << st++;
//    cout << st++;
//    cout << st.nAge;
//    system("pause");
//    return 0;
//}
