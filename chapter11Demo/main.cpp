#include <iostream>
#include "LandOwnerV2.h"
#include "LandOwnerV3.h"
#include "Student.h"
#include "LandOwner.h"

using namespace std;

int main()
{
    /*
    landOwnerV1 landowner1; //声明了一个landownerV1类型的变量

    //landowner1.cards[0] = 9;        //不能直接使用对象的私有成员
    landowner1.TouchCard(100);
    */
/*
    LandOwnerV2 landOwner2;
    landOwner2.name = "郭德纲";
    landOwner2.TouchCard(20);
    landOwner2.ShowScore(100);
    landOwner2.ShowScore(100);
*/
/*
    LandOwnerV3 landOwner3;
    landOwner3.name = "巴依老爷";
    //landOwner3.score = 100;
    landOwner3.SetScore(-100);
    landOwner3.ShowScore();
    */
    /*
    Student stu1;
    Student stu2("马化腾","普通家庭");
    //Student stu3(20);
    stu2.ShowInfo();
    Student *pstu5 = new Student("杰克马","汇创阿里");
    pstu5->ShowInfo();
    delete pstu5;
    */
    /*
    LandOwner *ptr_landOwner1 = new LandOwner();
    LandOwner *ptr_landOwner2 = new LandOwner("专业斗地主");
    LandOwner *ptr_landOwner3 = new LandOwner("周扒皮");

    ptr_landOwner1->ShowInfo();
    ptr_landOwner2->ShowInfo();
    ptr_landOwner3->ShowInfo();
    ptr_landOwner2->TouchCard(20);
    delete ptr_landOwner1;
    delete ptr_landOwner2;
    delete ptr_landOwner3;
    */
    Student *ptrStu1 = new Student("贝贝","微胖女孩");

    ptrStu1->AddScore(78.9f);
    ptrStu1->AddScore(88.9f);
    ptrStu1->AddScore(58.9f);
    ptrStu1->AddScore(68.9f);
    ptrStu1->AddScore(48.9f);
    ptrStu1->ShowInfo();

    Student stu2{"刘强丁","不知妻美"};
    stu2.AddScore(85);
    stu2.AddScore(65);
    stu2.AddScore(65);
    stu2.AddScore(45);
    stu2.AddScore(35);
    stu2.ShowInfo();
    Student &scholar1 = stu2.GetSuperScholar(*ptrStu1);
    Student &scholar2 = ptrStu1->GetSuperScholar(stu2);
    cout << "学霸是："  << scholar1.Getname() << endl;
    cout << "学霸是："  << scholar2.Getname() << endl;

    delete ptrStu1;

    return 0;
}
