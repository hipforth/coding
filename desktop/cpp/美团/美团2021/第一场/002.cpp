#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long  n;
    cin >> n;
    vector<pair<long long, long long> > vec;
    for(long long i = 1; i < n/4; i++)
    {
        string s1 = to_string(i);
        string s2 = to_string(4*i);
        reverse(s2.begin(), s2.end());
        if(s1 == s2)
        {
            vec.push_back({i, 4*i});
        }
    }
    if(vec.size() == 0) cout << 0;
    else
    {
        cout << vec.size() << endl;
        for(auto& v : vec)
        {
            cout << v.first << " " << v.second << endl;
        }
    }
    
    
    return 0;

}