#ifndef LANDOWNERV3_H
#define LANDOWNERV3_H
#include <iostream>
using namespace std;
class LandOwnerV3
{
    //private:

        int cards[20];
        long score;

    public:

        string name;
        LandOwnerV3();
        virtual ~LandOwnerV3();
        void ShowScore();
        void SetScore(long lScore)
        {
            if(lScore < 0)
                score = 0;
            else
                score = lScore;
        }


};

#endif // LANDOWNERV3_H
