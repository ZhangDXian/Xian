#include <iostream>

using namespace std;

int main()
{
    /*
    int nums[] {8,4,2,123,23,12};
    int numLen = sizeof(nums) / sizeof(int);
    int sum = 0;
    for(int i = 0;i < numLen;i++)
    {
        cout << nums[i] << '\t';
    }
    cout << endl;
    for(int i = 0;i < numLen;i++)
    {
        sum += nums[i];
    }
    cout << "���еĺ�Ϊ��" << sum << "\tƽ��ֵΪ��" << sum / numLen << endl;
    int max = nums[0];
    int maxIndex;
    for(int i = 1;i < numLen;i++)
    {
        if(nums[i] > max)
        {
            max = nums[i];
            maxIndex = i;
        }
    }
    cout << "���ֵ�ǣ�" << max << '/' << nums[maxIndex] << endl;;
    cout << "���ֵ���±��ǣ�" << maxIndex << endl;

    int unevenCount = 0;
    int evenCount = 0;
    for(int i = 0;i < numLen;i++)
    {
        if(nums[i] % 2 == 0)
            evenCount++;
        else
            unevenCount++;
    }
    cout << "ż���ĸ����ǣ�" << evenCount << endl;
    cout << "�����ĸ����ǣ�" << unevenCount << endl;

    int searchNum;
    int searchIndex = -1;
    cout << "������Ҫ���ҵ����֣�";
    cin >> searchNum;
    for(int i = 0;i < numLen;i++)
    {
        if(searchNum == nums[i])
        {
            searchIndex = i;
            break;
        }
    }
    if(searchIndex == -1)
        cout << "������û��������֣�" << endl;
    else
        cout << "�������е��±�Ϊ��" << searchIndex << endl;
    */
    int num[] {8,4,2,1,23,23,344,13};
    int numLen = sizeof(num) / sizeof(int);
    int min;
    int minIndex;
    int temp;
    for(int i = 0;i < numLen - 1;i++)
    {
        min = num[i];
        minIndex = i;
        for(int j = i + 1;j < numLen;j++)
        {
            if(num[j] < min)
            {
                min = num[j];
                minIndex = j;
            }
        }
        if(minIndex > i)
        {
            temp = num[minIndex];
            num[minIndex] = num[i];
            num[i] = temp;
        }
    }

    for(int i = 0;i < numLen;i++)
        cout << num[i] << endl;

    return 0;
}
