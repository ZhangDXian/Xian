#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;
template <int N>
int (*return_arrayP())[N]
{
    static int array[] = {2, 3, 4};
    return &array;
}

template <int N>
int (&return_arrayR())[N]
{
    static int array[] = {2, 3, 4};
    return array;
}

int main()
{
    static const int N = 3;
    // test return pointer to array
    std::cout << "test return pointer to array\n";
    int (*arrayP)[N] = return_arrayP<N>();
    for (int i = 0; i < N; i++) {
        std::cout << (*arrayP)[i] << ", ";
    }
    std::cout << "\n";

    // test return reference to array
    std::cout << "test return reference to array\n";
    int (&arrayR)[N] = return_arrayR<N>();
    for (int i = 0; i < N; i++) {
        std::cout << arrayR[i] << ", ";
    }
    std::cout << "\n";

    // boost::array return reference to array
    // to downcast to T*
    std::cout << "use boost::array to return reference to array, and then downcast to T*\n";
    int* arrayb = NULL;
    boost::array<int, N> oneArray = {1, 2, 3};
    arrayb = boost::get_c_array(oneArray);
    for (int i = 0; i < N; i++) {
        std::cout << arrayb[i] << ", ";
    }
    std::cout << "\n";


   // string s = "word";
    //string p1 = s + s[s.size() - 1] == 's' ? "" : "s";
    //cout << "买买买" << endl;
    /*
    vector<double> vecDouble {98.5,67.9,43.6,23.1,25.4};
    vecDouble.push_back(100.8);

    int &get(int *arry, int index) { return arry[index]; }
//返回给定数组元素的引用
int main() {
    int ia[10];  // array of ten uninitialized ints

    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;  // call get to assign values to the elements

    for (int i = 0; i != 10; ++i)  // print the elements
        cout << ia[i] << " ";

    cout << endl;

    return 0;
}

    vector<double>::iterator it;    //得到迭代器对象
    for(it = vecDouble.begin();it != vecDouble.end();++it)
    {
        cout << *it << endl;
    }
    sort(vecDouble.begin(),vecDouble.end());
    reverse(vecDouble.begin(),vecDouble.end());
    for(it = vecDouble.begin();it != vecDouble.end();++it)
    {
        cout << *it << endl;
    }
    it = vecDouble.end();
    vecDouble.erase(--it);
    vecDouble.pop_back();
    for(it = vecDouble.begin();it != vecDouble.end();++it)
    {
        cout << *it << endl;
    }
    */

    return 0;
}






