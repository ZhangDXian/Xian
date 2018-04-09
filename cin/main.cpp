#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //int num = 42;
    //cout << num;

    /*char pan = '\0';
    cout << "请输入一个字符：";
    cin >> pan;
    if(pan >= 'A' && pan <= 'Z')
    {
        cout << "是合法的" << endl;
    }
    else
        cout << "不合法的" << endl;
    */
    double price_louis = 35000.0;
    double price_hames = 11044.5;
    double price_chanel = 1535.0;
    double zhekou;
    double total = 0;
    total = price_louis + price_hames + price_chanel;
    if(total > 50000)
        zhekou = 0.7;
    else
        zhekou = 0.9;
    total *= zhekou;

    cout << total << endl;









    /*
    string str = "Hello World!";
    cout << str << endl;
    */

    /*
    int num;
    char ch1,ch2,ch3,ch4;
    cout << "请输入一个数字：";
    cin >> num; //  scanf(%d,&num);
    cin >> ch1 >> ch2 >> ch3;
    cout << num << "\t" << ch1 << '\t' << ch2 << '\t' << ch3;
    */
    return 0;
}
