#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <array>

using namespace std;

int main()
{
    /** ���׵�����*/
    string value_father_name;
    /** Ů��������*/
    string value_daughter_name;
    /** Ů�������·�*/
    int value_birth_month;
    /**Ů��������*/
    int value_brith_date;
    /** Ů��������*/
    string value_daughter_constell;
    /** Ů�������������Ϣ�� ���������������������¡�����*/
    vector<int> value_daufhter_baseInfo;
    /** ������ά����*/
    string constell_names[12][2] = {
        {"ɽ����","ˮƿ��"},
        {"ˮƿ��","˫����"},
        {"˫����","������"},
        {"������","��ţ��"},
        {"��ţ��","˫����"},
        {"˫����","��з��"},
        {"��з��","ʨ����"},
        {"ʨ����","��Ů��"},
        {"��Ů��","�����"},
        {"�����","��Ы��"},
        {"��Ы��","������"},
        {"������","ɽ����"}
    };

    cout << "���׵�������";
    cin >> value_father_name;
    cout << "Ů����������";
    cin >> value_daughter_name;
    cout << "Ů�������գ�(MM DD)";
    cin >> value_birth_month >> value_brith_date;

    /** ���·ݵĿ���������*/
    int constell_dates[] {20,19,21,20,21,22,23,23,23,24,23,22};

    value_daughter_constell = constell_names[value_birth_month - 1][value_brith_date / constell_dates[value_birth_month - 1]];

    cout << "Ů������Ϣ��";
    cout << "������" << value_daughter_name << endl;
    cout << "���գ�1659-" << value_birth_month << '-' <<value_brith_date << endl;
    cout << "������" << value_daughter_constell << endl;


    return 0;
}
