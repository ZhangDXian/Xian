/**
 *�ļ�����
 *������
 *���ߣ�
 *ʱ�䣺
 *��Ȩ��
 */
 #include <iostream>
 #include "LandOwnerV2.h"
 using namespace std;

LandOwnerV2::LandOwnerV2()
{
    //ctor
}
void LandOwnerV2::TouchCard(int cardCount)
{
    cout << name << "����" << cardCount << "����" << endl;
}
void LandOwnerV2::ShowScore(int score)
{
    cout << name << "��ǰ�Ļ���Ϊ��"  << score << endl;
}

LandOwnerV2::~LandOwnerV2()
{
    //dtor
}
