#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <array>

using namespace std;

int main()
{
    /** 父亲的姓名*/
    string value_father_name;
    /** 女儿的姓名*/
    string value_daughter_name;
    /** 女儿生日月份*/
    int value_birth_month;
    /**女儿生日期*/
    int value_brith_date;
    /** 女儿的星座*/
    string value_daughter_constell;
    /** 女儿的五项基本信息： 体力、智力、魅力、道德、气质*/
    vector<int> value_daufhter_baseInfo;
    /** 星座二维数字*/
    string constell_names[12][2] = {
        {"山羊座","水瓶座"},
        {"水瓶座","双鱼座"},
        {"双鱼座","白羊座"},
        {"白羊座","金牛座"},
        {"金牛座","双子座"},
        {"双子座","巨蟹座"},
        {"巨蟹座","狮子座"},
        {"狮子座","处女座"},
        {"处女座","天秤座"},
        {"天秤座","天蝎座"},
        {"天蝎座","射手座"},
        {"射手座","山羊座"}
    };

    cout << "父亲的姓名：";
    cin >> value_father_name;
    cout << "女儿的姓名：";
    cin >> value_daughter_name;
    cout << "女儿的生日：(MM DD)";
    cin >> value_birth_month >> value_brith_date;

    /** 过月份的跨星座日期*/
    int constell_dates[] {20,19,21,20,21,22,23,23,23,24,23,22};

    value_daughter_constell = constell_names[value_birth_month - 1][value_brith_date / constell_dates[value_birth_month - 1]];

    cout << "女儿的信息：";
    cout << "姓名：" << value_daughter_name << endl;
    cout << "生日：1659-" << value_birth_month << '-' <<value_brith_date << endl;
    cout << "星座：" << value_daughter_constell << endl;


    return 0;
}
