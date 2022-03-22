#include <bits/stdc++.h>

using namespace std;

bool _check(unordered_map<int, set<int>>& daolu, stack<int>& _stack)
{
    int city = _stack.top();
    _stack.pop();
    while(!_stack.empty())
    {
        int ct = _stack.top();
        _stack.pop();
        auto iter = daolu.find(city);
        if(iter != daolu.end())
        {
            if(iter->second.size() != 0)
            {
                if(!daolu.count(ct))
                {
                    return false;
                }
            }
        }
        city = ct;

    }
    return true;
}



int main()
{
    int T;
    cin >> T;
    vector<bool> _flag;
    while(T--)
    {
       	int n, m, k;
    	cin >> n >> m >>k;
        vector<int> vec;
        stack<int> _stack;//存储旅行记录长度
        unordered_map<int, set<int>> daolu;//道路
        while(m--)
        {
            int u, v;
            cin >> u >> v;
            daolu[u].insert(v);
            daolu[v].insert(u);
        }
        while(k--)
        {
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }
        for(int i = vec.size()-1; i >=0; i--)
        {
            _stack.push(vec[i]);
        }
        bool flag = _check(daolu, _stack);
        _flag.push_back(flag);
        
    }
    for(auto x : _flag)
    {
        if(x) cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
        }
        
    }
    return 0;
}
/*

2
4 2 3
1 2
2 3
1 2 3
4 2 3
1 2
2 3
1 2 4

*/