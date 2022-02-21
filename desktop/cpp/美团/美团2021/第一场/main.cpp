/*小美的送花线路
 * 遍历所有深度
 *
 *  
 */
#include <bits/stdc++.h>

using namespace std;




int main() {

    int n;
    cin >> n;
    unordered_map<int, vector<pair<int, int> > > mp;
    int total = 0;
    while(n--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mp[u].push_back({v, w});
        total += w;
    }
    queue<pair<int, int> > q;
    q.push({1, 0});
    int maxLength = -1, sumLength = 0;
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int len = mp[p.first].size();
        if(!len)
        {
            maxLength = max(maxLength, p.second);
        }
        else
        {
            for(int i = 0; i < len; i++)
            {
                pair<int, int> tmp = mp[p.first][i];
                q.push({tmp.first, p.second + tmp.second});
                sumLength += (p.second + tmp.second);
            }
        }
        
    }
    total = total * 2 - maxLength;
    cout << sumLength << ' ' << total << endl;

    return 0;
}