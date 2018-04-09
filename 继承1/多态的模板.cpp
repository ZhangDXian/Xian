//#include <iostream>
//using namespace std;
//
//template<typename T,typename Y>
//class CFather
//{
//public:
//   virtual void fun()
//   {
//       cout << "CFather" << endl;
//   }
//
//};
//template<typename X,typename Z,typename W>
//class CSon : public CFather<X,Z>
//{
//public:
//    void fun()
//    {
//        cout << "CSon" << endl;
//    }
//};
//
//int main()
//{
//    CFather<int,char>* pf = new CSon<int,char,short>;
//    pf->fun();
//}
