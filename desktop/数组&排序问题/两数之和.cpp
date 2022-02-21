#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& vec, int target)
{
    unordered_map<int, int> mp;
    int n = vec.size();
    for(int i = 0; i < n; i++)
    {
        auto it = mp.find(target - i);
        if(it != mp.end())
        {
            return {it->second, i};
        }
        mp[vec[i]] = i;
    }
    return {};
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> vec;
    while(n--)
    {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    twoSum(vec, target);
    return 0;
}