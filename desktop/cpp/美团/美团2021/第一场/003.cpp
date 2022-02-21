#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int travel = 0;
    vector<pair<string, string> > S;
    while (n--)
    {
        string s0;
        cin >> s0;
        string s1;
        cin >> s1;
        // if(s0 == s1)
        // {
        //     travel++;
        //     continue;
        // } 
        
        S.push_back({s0, s1});
    }
    
    string s0 = " ";
    for(auto s : S)
    {
        if(s0 == " ")
        {
            s0 = s.first;
        }
        if(s0 == s.second)
        {
            travel++;
            s0 = " ";
        }
    }
    cout << travel;

    return 0;
}