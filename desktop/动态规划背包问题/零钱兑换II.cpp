#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int> > vec(n+1, vector<int>(amount+1, 0));
        vec[0][0] = 1;
        for(int j = 0; j <= amount; j++)
        {
            for(int i = 1; i <= n; i++)
            {
                int coin = coins[i-1];
                int tmp = 0;
                for(int k = 0; k*coin <= j; k++)
                    tmp += vec[i-1][j - k*coin];
                vec[i][j] = tmp;
            }
        }
        return vec[n][amount];
    }
};

int main()
{
    Solution solu;
    int n, m;
    cin >> n >> m;
    vector<int> vec;
    while(n--)
    {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    cout << solu.change(m,vec) << endl;;
    return 0;
}