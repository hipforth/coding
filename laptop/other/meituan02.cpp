#include <bits/stdc++.h>

using namespace std;

const int N =1010;
int v[N], w[N];
int f[N][N];
int n, m , k;
int sum;
unordered_map<int,bool> q;

bool dp(){
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= k; j++){
            f[i][j] = f[i - 1][j];
            if(j >= v[i]) {
               f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i] * w[i] * w[i]);
               q[i] = true;
            }
            q[i] = false;
        }
    }
    int res = 0;
    for(int i = 1; i <= m; i++){
        //cout << w[i] << endl;
        if(!q[i]) res += w[i];
    }
    res += f[m][k];
    if(res >= sum) return true;
    return false;
}

int main(){
   cin >> n;
   while(n--){
       cin >> m >> k >> sum;
       for(int i = 1; i <= m; i++){
           int a;
           cin >> a;
           v[i] = 1, w[i] = a;
       }
       if(dp()){
           cout << "YES"<< endl;
       }
       else{
           cout <<"NO" << endl;
       }
   }
    return 0;
}
