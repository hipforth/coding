#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int> > mp;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a <= b) mp[a].push_back(b);
        else
        {
            int tmp;
            tmp = a;
            a = b;
            b = tmp;
            mp[a].push_back(b);
        }
    }


    
    int x = 0;
    
    set<int> s;
    queue<int> q;
    q.push(1);
    s.insert(1);
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        int len = mp[front].size();
        if(len != 0)
        {
            for(int i = 0; i < len; i++)
            {
                q.push(mp[front][i]);
                if(mp[front][i] != 0)
                    s.insert(mp[front][i]);
                mp[front][i] = 0;
                //cout << mp[front][i] << endl;
            }
        }
    }
    for(auto& _s : s){
        cout << _s << " ";
    }
    return 0;
}
/*
5 5
1 2
2 2
3 1
4 2
5 4
*/