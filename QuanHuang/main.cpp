#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int hp1 = 100,
        hp2 = 100;
    int attack1 = 0;
    int attack2 = 0;
    int randNum;
    int n = 1;
    srand(time(NULL));

    while(hp1 > 0 && hp2 > 0)
    {
        randNum = rand();
        if(randNum % 2 == 1)
        {
            attack1 = (int)(5 + 10 * rand() / (RAND_MAX + 1.0));
            attack2 = (int)(5 + 10 * rand() / (RAND_MAX + 1.0));
            hp2 -= attack1;
            hp1 -= attack2;
        }
        else
        {
            attack2 = (int)(5 + 10 * rand() / (RAND_MAX + 1.0));
            attack1 = (int)(5 + 10 * rand() / (RAND_MAX + 1.0));
            hp1 -= attack1;
            hp2 -= attack2;
        }
        cout << "��" << n << "�غ�" << endl;
        cout << "����ǰѪ��ֵ��" << hp1 << "���S����ǰѪ����" << hp2 << endl;
        n++;
    }
    return 0;
}
