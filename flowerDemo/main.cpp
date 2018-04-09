#include <iostream>

using namespace std;

int main()
{
    double score[] {11,22,33,44,55};
    double* ptr_score = score;

    cout << score << '\t' << sizeof(ptr_score) << endl;
    return 0;
}
