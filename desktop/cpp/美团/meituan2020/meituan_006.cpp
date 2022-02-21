#include <bits/stdc++.h>

using namespace std;

void uncode(string& s, int& n) {
    int l_M = 0;
    int l_T = 0;
    int r_M = 0;
    int r_T = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'M' && !l_M) l_M = i+1;
        if(s[i] == 'T' && !l_T && l_M) l_T = i+1;
    }
    for(int i = n - 1; i >=0; i--){
        if(s[i] == 'T' && !r_T) r_T = i+1;
        if(s[i] == 'M' && !r_M && r_T) r_M = i+1;
    }
    for(int i = l_T; i < r_M - 1; i++) {
        cout << s[i];
    }
}

int main() {

    
    int n;
    cin >> n;
    string s;
    cin >> s;
    uncode(s, n);
    return 0;
}