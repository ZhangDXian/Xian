#ifndef LANDOWERV2_H
#define LANDOWERV2_H

using namespace std;

class LandOwnerV2
{
    public:
        string name;
        long score;
        int cards[20];
    public:
        LandOwerV2();               //���캯��������
        virtual ~LandOwerV2();      //��������������

        void TouchCard(int );
        void ShowScore();
    protected:


};

#endif // LANDOWERV2_H
