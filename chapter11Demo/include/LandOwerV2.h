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
        LandOwerV2();               //构造函数的声明
        virtual ~LandOwerV2();      //析构函数的声明

        void TouchCard(int );
        void ShowScore();
    protected:


};

#endif // LANDOWERV2_H
