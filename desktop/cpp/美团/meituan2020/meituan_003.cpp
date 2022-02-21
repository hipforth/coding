#include <bits/stdc++.h>

using namespace std;

struct VW
{
    int i;
    int money;
};

// int quzheng(int w) {
//     if(w >= 1) return w*2;
//     else return 0;
// }

bool my_sort(VW a, VW b) {
    if(a.money == b.money) return a.i < b.i;
    return a.money > b.money;
}

bool my_sort_1(VW a, VW b) {
    return a.i < b.i;
}

int main() {
    int n, m;
    cin >> n >> m;
   // multimap< int, int, greater<int> > money;
    vector<VW> meituan;
    VW _meituan;
    for(int i = 0; i < n; i++) {
        int v, w;
        cin >> v >> w;
        _meituan.i = i+1;
        _meituan.money = v + 2*w;
        meituan.push_back(_meituan);
    }
    sort(meituan.begin(), meituan.end(), my_sort);

    sort(meituan.begin(), meituan.begin() + m, my_sort_1);

    for(int i = 0; i < m; i ++) {
        cout << meituan[i].i << " ";
    }

    return 0;
}