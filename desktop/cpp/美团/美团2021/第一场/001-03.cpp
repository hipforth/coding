#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum_value = 0;//总价值
    int sum_cost = 0;//总花费
    while(n--)
    {
        int x, y;
        cin >> x >> y;
        sum_value += (x-y) >=0 ? x : y;
        sum_cost += (x - y) >= 0 ? (x-y) : 0;
    }
    cout << sum_value << " " << sum_cost;

    return 0;
}