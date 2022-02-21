#include <bits/stdc++.h>

using namespace std;



int main() {

    int n;
    cin >> n;
    string s;
    cin >> s;
    int curent_max = 0, result_max = 0;
    for(int i = 0; i < n; i++) {
        char c = s[i];
        int x = c == 'E' ? 1 : -1;
        curent_max = max(x+curent_max, x);
        result_max = max(result_max, curent_max);
    }

    cout << result_max;
    return 0;
}