#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>
#include <climits>

using namespace std;

int main()
{
    //��������֮��
    SetConsoleTitle("��ӡ��������֮������ϸ��Ϣ");
    /**�˺�*/
    double value_attack = 57.88;
    /**�˺��ɳ�ֵ*/
    double value_attack_grouth = 4.5;
    /**��������*/
    double value_attack_distance = 172;
    /**����ֵ*/
    double value_defence = 27.54;
    /**���׳ɳ�ֵ*/
    double value_defence_growth = 3.0;

    cout << "���ƣ���������֮��" << endl;
    cout << "�˺���" << value_attack << "(+" << value_attack_grouth << ")\t"
         << "�������룺" << value_attack_distance << endl;
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
