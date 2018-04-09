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
//    double dbHeight;
//public:
//    CStu()
//    {
//        nAge = 0;
//        dbHeight = 0.0;
//    }
//    int operator+(int a)    //this 类 + a
//    {
//        return (nAge + a);
//    }
//    int operator!()
//    {
//        return (!nAge);
//    }
//    void Show()
//    {
//        cout << nAge << endl;
//        cout << dbHeight << endl;
//    }
//    int operator = (int a)
//    {
//        nAge = a;
//        return nAge;
//    }
//    friend ostream& operator << (ostream& os,const CStu& st);
//    friend istream& operator >> (istream& is,CStu& st);
//    friend CStu& operator += (CStu& st,int a);
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
//istream& operator >> (istream& is,CStu& st)
//{
//    is >> st.nAge >> st.dbHeight;
//    if(is.fail())
//    {
//        st.nAge = 0;
//        st.dbHeight = 0;
//    }
//    return is;
//}
//CStu& operator += (CStu& st,int a)
//{
//    st.nAge = st.nAge + a;
//    return st;
//}
//int main()
//{
//    CStu st;
//    st += 123 += 123;
//    cout << (st += 123);
//    st.Show();
//
//    system("pause");
//    return 0;
//}
