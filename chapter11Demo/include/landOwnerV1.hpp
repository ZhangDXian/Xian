#ifndef LANDOWNERV1_H
#define LANDOWNERV1_H
#include <iostream>

using namespace std;

/**
 *  .hpp�ļ�һ�����ʵ�ֵ���������,ͨ������ģ��������������ʵ�ֹ�������
 *  ���飺ֻҪ���Ǵ�ģ�壬һ��һ��ʹ�á�h��Ϊͷ�ļ���ʹ�á�coo�ļ���Ϊ����ʵ���ļ�
 */
class landOwnerV1
{
    private:
        string name;    //����������
        long score;     //�����Ļ���
        int cards[20];  //����������
    public:
        landOwnerV1() {}    //ʵ����Ĭ�Ϲ��캯��
         ~landOwnerV1() {}
        inline void TouchCard(int cardCount)
        {
            cout << name << "����" << cardCount << "����" << endl;
        }
        void Showscore()
        {
            cout << name << "��ǰ�Ļ���Ϊ��"  << score << endl;
        }
    protected:


};

#endif // LANDOWNERV1_H
