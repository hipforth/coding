#include <bits/stdc++.h>

using namespace std;

bool my_sort(pair<int, int> a, pair<int, int> b)
{
    return a.second == b.second ? a.first < b.first : a.second > b.second;
}

bool my_sort_1(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > vec;
    for(int i = 1; i <= n; i++)
    {
        int v, w, sum;
        cin >> v >> w;
        sum = v + w*2;
        vec.push_back({i, sum});
    }
    sort(vec.begin(), vec.end(), my_sort);
    sort(vec.begin(), vec.begin()+m, my_sort_1);
    for(int i = 0; i < m; i++)
    {
        cout << vec[i].first << " ";
    }
    return 0;
}

// 5 2
// 5 10
// 8 9
// 1 4
// 7 9
// 6 10