#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

using namespace std;
class Student
{
    public:
        Student();
        Student(string,string);
        Student(int);
        virtual ~Student();

        void ShowInfo();
        string Getname() { return m_name; }
        void Setname(string val) { m_name = val; }
        string Getdesc() { return m_desc; }
        void Setdesc(string val) { m_desc = val; }
        int Getage() { return m_age; }
        void Setage(int val)
        {
            if(val < 0)
                m_age = 18;
            else
                m_age = val;
        }
        void InitScores();  //初始化学生成绩数组，默认分配一个元素空间
        void AddScore(float);   //向scores数组中添加一个分数
        Student& GetSuperScholar(Student& );
        //函数结尾声明const ：函数内部不允许修改对象本书，调用非const方法会报错
        float GetTotal();

    protected:

    private:
        string m_name;
        string m_desc;
        int m_age;
        int scoreCount; //学生成绩个数
        float *scores;  //分数数组
};

#endif // STUDENT_H
