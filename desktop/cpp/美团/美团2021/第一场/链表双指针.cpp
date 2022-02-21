#include <bits/stdc++.h>

using namespace std;

int result = 0;

int meituan004(list<int>& x)
{
    auto iter_pre = x.begin();
    auto iter = x.begin();
    if(iter == x.end()) return 0;
    iter++;
    if(iter == x.end()) return 0;
    int t = 0;
    for(;iter != x.end(); ){
        if(*iter_pre == *iter) 
        {
            result += 1;
            auto tmp = iter;
            iter++;
            *iter_pre = *iter_pre + 1;
             x.erase(tmp);
            //iter_pre++;
            t++;
        }
        else
        {
            iter++;
            iter_pre++;
        }
        
    }
    return t;
}

int main()
{
    int n;
    cin >> n;
    list<int> x;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        x.push_back(tmp);
    }
    while(n--)
    {
        if(meituan004(x) == 0) 
        {
            cout << result;
            break;
        }
    }
    return 0;
}