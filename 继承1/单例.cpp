//#include <iostream>
//using namespace std;
//
//class CFather
//{
//private:
//    CFather()
//    {
//
//    }
//
//public:
//    static int nFlag;
//    static CFather* GreateOJ()
//    {
//        if(1 == nFlag)
//        {
//            nFlag = 0;
//            return (new CFather);
//
//        }
//        else
//            return nullptr;
//
//    }
//    ~CFather()
//    {
//        nFlag = 1;
//    }
//};
//class CSon : public CFather
//{
//
//};
//
//int CFather::nFlag = 1;
//
//
//int main()
//{
//    CFather* pf = CFather::GreateOJ();
//    delete pf;
//    CFather* pf1 = CFather::GreateOJ();
//    if(pf1 == nullptr)
//    {
//
//    }
//    return 0;
//}
