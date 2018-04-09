/**
 *文件名：
 *描述：
 *作者：
 *时间：
 *版权：
 */#include "Student.h"

Student::Student()
{
    cout << "默认构造" << endl;
}
Student::Student(int age)
{
    m_age = age;
    cout << "默认带参构造：Student(int age)" << endl;
    InitScores();
}
Student::Student(string name,string desc)
{
    //等价写法
    //m_name = name;
    Setname(name);
    Setdesc(desc);
    cout << "默认带参构造： Student(string name,string desc)" << endl;
    InitScores();
}
void Student::ShowInfo()
{
    cout << m_desc << m_name << endl;
    for(int i = 0;i != scoreCount - 1;++i)
    {
        cout << this->scores[i] << "\t";
    }
    cout << endl;
}
void Student::InitScores()
{
    this->scores = new float[1];
    this->scoreCount = 1;
}
void Student::AddScore(float score)
{
    this->scores[this->scoreCount - 1] = score;
    //创建一个新数组，分配scoreCount + 1 个空间
    //复制原数组中的内容到新数组中
    //scorecount++
    //scores指向新数组
    float *newScores = new float[scoreCount + 1];
    float *oldScores = scores;
    memcpy(newScores,scores,sizeof(float) * scoreCount);
    scoreCount++;
    scores = newScores;
    delete oldScores;
}
Student& Student::GetSuperScholar(Student &otherStu)
{
    //分别计算两个学生的总分
    if(this->GetTotal() > otherStu.GetTotal())
        return *this;
    else
        return otherStu;

}
float Student::GetTotal()
{
    float sum = 0;
    for(int i = 0;i != scoreCount - 1;i++)
    {
        sum += scores[i];
    }
    return sum;
}

Student::~Student()
{
    cout << m_name << "被释放" << endl;
    delete this->scores;
}
