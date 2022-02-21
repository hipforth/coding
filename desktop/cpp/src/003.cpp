#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<int, vector<pair<int, int> > > dis;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u].push_back({v,w});
    }
    int maxLength = 0, sumLength = 0;
    int qishou_length = 0;
    queue<pair<int, int> > q;
    for(int i = 0; i < dis[1].size(); i++)
    {
        int tmp = dis[1][i].second;
        q.push(dis[1][i]);
        qishou_length += tmp;
        maxLength = max(maxLength,tmp);
        sumLength += tmp;
    }
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int tmp = p.second;
        for(int i = 0; i < dis[p.first].size(); i++)
        {
            int a = dis[p.first][i].first;
            int b = dis[p.first][i].second;
            q.push({a,b + tmp});
            qishou_length += b;
            sumLength += b + tmp;
            maxLength = max(maxLength, b + tmp);
        }
    }
    qishou_length  = qishou_length * 2 - maxLength;
    cout << sumLength << " " << qishou_length;

    return 0;
}

