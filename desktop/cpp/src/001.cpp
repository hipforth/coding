#include <bits/stdc++.h>

using namespace std;




int main()
{
    string s;
    cing >> s;
    int n = s.size();
    list<char> ab;
    for(int i = 0; i < n; i++)
    {
        ab.push_back(s[i]);
    }
    auto iter_l = ab.end();
    if(iter_l != ab.begin())
    {
        iter_l --;
    }
    else
    {
        cout << "0";
        return 0;
    }
    if(iter_l != ab.begin()){
        auto iter_r = iter_l;
        iter_r --;
    }
    for( ; iter_r != ab.begin(); )
    {
        if(*iter_l == 'b' && *iter_r == 'a') 
        {
            *iter_r = 'b';
            ab.insert(iter_l+1, 'a');
        }
    }

}