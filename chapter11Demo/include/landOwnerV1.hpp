#ifndef LANDOWNERV1_H
#define LANDOWNERV1_H
#include <iostream>

using namespace std;

/**
 *  .hpp文件一般包含实现的内联函数,通常用于模板类这种声明与实现共存的情况
 *  建议：只要不是纯模板，一般一律使用。h作为头文件，使用。coo文件作为函数实现文件
 */
class landOwnerV1
{
    private:
        string name;    //地主的名称
        long score;     //地主的积分
        int cards[20];  //地主的手牌
    public:
        landOwnerV1() {}    //实现了默认构造函数
         ~landOwnerV1() {}
        inline void TouchCard(int cardCount)
        {
            cout << name << "摸了" << cardCount << "张牌" << endl;
        }
        void Showscore()
        {
            cout << name << "当前的积分为："  << score << endl;
        }
    protected:


};

#endif // LANDOWNERV1_H
