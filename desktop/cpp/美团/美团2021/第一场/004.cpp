#include <bits/stdc++.h>

using namespace std;

bool greater_sort_x(pair<int, int> a ,pair<int, int> b)
{
    return a.first > b.first;
}

bool greater_sort_y(pair<int, int> a ,pair<int, int> b)
{
    return a.second > b.second;
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<pair<int, int> > xy;
    while(n--)
    {
        int x, y;
        cin >> x >> y;
        xy.push_back({x, y});
    }
    int sum = 0;
    if(a >= b)
    {
        sort(xy.begin(), xy.end(), greater_sort_x);
        for(int i = 0; i < a; i++)
        {
            sum += xy[i].first;
        }
        sort(xy.begin()+a, xy.end(), greater_sort_y);
        for(int i = a; i < a+b; i ++)
        {
            sum += xy[i].second;
        }
        
    }   
    else
    {
        sort(xy.begin(), xy.end(), greater_sort_y);
        for(int i = 0; i < b; i++)
        {
            sum += xy[i].first;
        }
        sort(xy.begin()+b, xy.end(), greater_sort_x);
        for(int i = b; i < a+b; i ++)
        {
            sum += xy[i].second;
        }
    }
    cout << sum;
    return 0;
}