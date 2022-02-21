#include "bits/stdc++.h"

using namespace std;

//这种特殊情况可以用异或

int main()
{
    vector<int> vec = {
        1, 3, 4, 7, 3, 1, 7, 4, 0
    };
    int result = 0;
    for(int i = 0; i < vec.size(); i++)
    {
        result = result^vec[i];
    }
    cout << result << endl;
    return 0;
}