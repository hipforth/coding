#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    while(n--)
    {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    int sum = 0;
    int minNum = vec[0];
    for(int i = 0; i < vec.size() - 1; i++)
    {
        if(vec[i] >= vec[i+1])
        {
            minNum = min(minNum, vec[i+1]);
        }
        else
        {
            sum = max(sum, vec[i+1] - minNum);
        }
    }
    cout << sum << endl;
    return 0;
}