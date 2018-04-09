#ifndef LANDOWNERV2_H
#define LANDOWNERV2_H

#include <iostream>
using namespace std;

class LandOwnerV2
{
    public:
        string name;
        long score;
        int cards[20];
    public:
        LandOwnerV2();
        ~LandOwnerV2();

        void TouchCard(int );
        void ShowScore(int);

    protected:


};

#endif // LANDOWNERV2_H
