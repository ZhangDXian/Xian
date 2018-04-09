#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>
#include <climits>

using namespace std;

int main()
{
    //德玛西亚之力
    SetConsoleTitle("打印德玛西亚之力的详细信息");
    /**伤害*/
    double value_attack = 57.88;
    /**伤害成长值*/
    double value_attack_grouth = 4.5;
    /**攻击距离*/
    double value_attack_distance = 172;
    /**护甲值*/
    double value_defence = 27.54;
    /**护甲成长值*/
    double value_defence_growth = 3.0;

    cout << "名称：德玛西亚之力" << endl;
    cout << "伤害：" << value_attack << "(+" << value_attack_grouth << ")\t"
         << "攻击距离：" << value_attack_distance << endl;
    cout << CHAR_MAX << endl;
    cout << 'A' + ' ' << endl;

    /*
    float numFloat = 10 / 3.0;
    double numDouble = 10 / 3.0 ;
    cout << fixed;
    cout << setprecision(2);
    cout << "numFloat = " << numFloat * 100000000<< endl;
    cout << "numDouble = " << numDouble * 100000000<< endl;
    */
    /*
    cout << sizeof(double) << endl;
    cout << sizeof(long double) << endl;
    cout << sizeof(3.14) << endl;
    cout << sizeof(union) << endl;
    return 0;
    */
}
