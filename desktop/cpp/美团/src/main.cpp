#include <bits/stdc++.h>

using namespace std;

void _function(int m, int n)
{
    int flag = false;
    for(int i = m; i <= n; i++)
    {
        {
            int tmp = i;
            vector<int> vec;
            while(tmp)
            {
                vec.push_back(tmp % 10);
                tmp = tmp / 10;
            }
            int sum = 0;
            for(int j = 0; j < vec.size(); j++)
            {
                sum += vec[j] * vec[j] * vec[j];
            }
            if(sum == i) 
            {
                flag = true;
                cout << i << " ";
            }
        }
    }
    if(flag)
        cout << endl;
    else
    {
        cout << "no" << endl;
    }
    
}

int main()
{
    int m, n;
    while(cin >> m >> n)
    {
        _function(m, n);
    }
    return 0;
}