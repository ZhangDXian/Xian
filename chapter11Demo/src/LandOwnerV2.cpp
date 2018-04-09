/**
 *文件名：
 *描述：
 *作者：
 *时间：
 *版权：
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
    cout << name << "摸了" << cardCount << "张牌" << endl;
}
void LandOwnerV2::ShowScore(int score)
{
    cout << name << "当前的积分为："  << score << endl;
}

LandOwnerV2::~LandOwnerV2()
{
    //dtor
}
