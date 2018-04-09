/**
 *�ļ�����
 *������
 *���ߣ�
 *ʱ�䣺
 *��Ȩ��
 */#include "LandOwner.h"


LandOwner::LandOwner()
{
    SetNickName("Ĭ�ϵ���");
    SetGold(1000);
    SetSex("����");
    SetExp(0);
    cout << "LandOwner()" << endl;
    InitCards();
}
LandOwner::LandOwner(string nickName): m_NickName(nickName)
{
    SetGold(1000);
    SetSex("����");
    SetExp(0);
    cout << "LandOwner(string nickName)" << endl;
    InitCards();
}
LandOwner::LandOwner(string nickName,string sex,int gold,long exp):m_NickName(nickName),m_Sex(sex),m_Gold(gold),m_Exp(exp)
{
    cout << "LandOwner(string nickName,string sex,int gold,long exp)" << endl;
    InitCards();
}
void LandOwner::ShowInfo()
{
    cout << "�ǳƣ�" << GetNickName() << endl;
    cout << "�Ա�" << GetSex() << endl;
    cout << "��ң�" << GetGold() << endl;
    cout << "���飺" << GetExp() << endl;
}
void LandOwner::InitCards()
{
    for(int i = 0;i != 54;i++)
    {
        packCards.push_back(i + 1);
        surplusCards.push_back(packCards.at(i));
    }
        currCards.clear();
        ShowCards(packCards);
}
void LandOwner::ShowCards(const vector<int> &cards)
{
    for(auto card: cards)
    {
        cout << card << ":" << getColor(card) << "-" << getValue(card) << ",";
    }
    cout << endl;
    /*for(int i = 0;i != cards.size();++i)
    {
        cout << cards[i] << ",";
    }
    cout << endl;
    */
    /*
    for(auto iter = cards.begin();iter != cards.end();++iter)
    {
        cout << *iter << ",";
    }
    cout << endl;
    */
    //copy(cards.cbegin(),cards.cend(),ostream_iterator<int>(cout,","));
    //cout << endl;
}
void LandOwner::TouchCard(int cardCount)
{
    srand(time(NULL));
    for(int i = 0;i != cardCount;i++)
    {
        int randIndex = rand() % 54;
        //������ɵ��������Ƿ���ʣ����Ƽ�����
        if(isContains(packCards[randIndex]))
        {
            currCards.push_back(packCards[randIndex]);
            deleteCard(surplusCards,packCards[randIndex]);
        }
        else
        {
            --i;
        }
    }
    cout << "<��������> - ��ǰ�������£�" << endl;
    ShowCards(currCards);
    cout << "<�������ƺ�> - ��ǰ�������£�" << endl;
    ShowCards(surplusCards);

}
bool LandOwner::isContains(int cardNum)
{
    /*
    for(int i = 0;i != surplusCards.size();++i)
    {
        if(surplusCards[i] == packCards[cardIndex])
    }
    */
    vector<int>::iterator iter = find(surplusCards.begin(),surplusCards.end(),cardNum);
    if(iter == surplusCards.end())
        return false;
    return true;

}
void LandOwner::deleteCard(vector<int>& cardVec,int card)
{
    /*
    for(auto iter = cardvec.cbegin();iter != cardVec.cend();)
    {
        if(*iter == card)
        {
            iter = cardVec.erase(card); //����ɾ�������һ��Ԫ��
        }
        else
            ++iter;
    }
    */
    auto iter = find(cardVec.begin(),cardVec.end(),card);
    if(iter != cardVec.end())
    {
        cardVec.erase(iter);    //card == iter ??
    }
}
string LandOwner::getColor(int card)
{
    if(card == 53) return "С��";
    if(card == 54) return "����";
    string Colors[] = {
        "����","����","��Ƭ","÷��"
    };
    return Colors[(card - 1) / 13];
}
string LandOwner::getValue(int card)
{
    if(card == 53) return "Black Joker";
    if(card == 54) return "Red Joker";
    string values[] = {
        "A","2","3","4","5","6","7","8","9","10","J","Q","K"
    };
    return values[(card - 1) % 13];
}
LandOwner::~LandOwner()
{
    cout << GetNickName() << "���ͷ�" << endl;
}










