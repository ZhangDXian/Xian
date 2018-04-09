#ifndef LANDOWNER_H
#define LANDOWNER_H
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

class LandOwner
{
    public:
        LandOwner();
        LandOwner(string);
        LandOwner(string,string,int,long);
        virtual ~LandOwner();

        string GetNickName() { return m_NickName; }
        void SetNickName(string val) { m_NickName = val; }
        string GetSex() { return m_Sex; }
        void SetSex(string val) { m_Sex = val; }
        int GetGold() { return m_Gold; }
        void SetGold(int val) { m_Gold = val; }
        long GetExp() { return m_Exp; }
        void SetExp(long val) { m_Exp = val; }

        void TouchCard(int cardCount);
        void ShowInfo();
        void InitCards();   //��ʼ��packCards��surrPlusCards,
        void ShowCards(const vector<int> &);
        bool isContains(int cardNum);   //ʣ�������Ƿ����cardNum�����
        void deleteCard(vector<int>&,int);
        string getColor(int);
        string getValue(int);

    protected:

    private:
        string m_NickName;
        string m_Sex;
        int m_Gold;
        long m_Exp;
        vector<int> packCards;      //Ĭ�ϵ�һ����
        vector<int> surplusCards;   //ʣ�����
        vector<int> currCards;      //��ǰ��ҵ�����
};

#endif // LANDOWNER_H
