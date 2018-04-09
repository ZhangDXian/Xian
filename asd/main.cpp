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
    cout << "数列的和为：" << sum << "\t平局值为：" << sum / numLen << endl;
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
    cout << "最大值是：" << max << '/' << nums[maxIndex] << endl;;
    cout << "最大值的下标是：" << maxIndex << endl;

    int unevenCount = 0;
    int evenCount = 0;
    for(int i = 0;i < numLen;i++)
    {
        if(nums[i] % 2 == 0)
            evenCount++;
        else
            unevenCount++;
    }
    cout << "偶数的个数是：" << evenCount << endl;
    cout << "奇数的个数是：" << unevenCount << endl;

    int searchNum;
    int searchIndex = -1;
    cout << "请输入要查找的数字：";
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
        cout << "数组中没有这个数字！" << endl;
    else
        cout << "在数组中的下表为：" << searchIndex << endl;
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
