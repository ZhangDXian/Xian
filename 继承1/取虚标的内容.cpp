//#include <iostream>
//using namespace std;
//
//class CFather
//{
//public:
//    virtual void Show()     //�麯����������
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
////    int aa;     //���ݲ���
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
//      //��ͨ��ֻ�ܵ������ڸ���ĳ�Ա
////    CSon* soso = new CSonSon;
////    soso->Show();
//    using p = void(*)();
//    ((p)*(int*)*(int*)fa)();
//    return 0;
//}
