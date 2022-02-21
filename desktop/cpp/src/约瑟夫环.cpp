#include <bits/stdc++.h>

using namespace std;

int ysf(int n, int m)
{
    return f(n, m);
}

int f(int n, int m)
{
    if(n == 1) return 0;
    return (f(n-1, m) + m) % n;
}

int ysf_1(int n, int m)
{
    int f = 0;
    for(int i = 2; i <= n; i++)
    {
        f = (f + m) % i;
    }
    return f;
}

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for(auto& ev: knowledge){
            mp[ev[0]] = ev[1];
        }
        string ans;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                string last;
                for(int j = i + 1; j < s.size(); ++j){
                    if(s[j] != ')') last += s[j];
                    else {
                        i = j;
                        break;
                    }
                }
                if(mp.count(last)) ans += mp[last];
                else ans += "?";
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};


void zfc(string& s)
{
    int n = s.size();
    string result;
    int slow = 0;
    int fast = 1;
    while(fast < n)
    {
        if(s[slow] >= '0' && s[slow] <= '9')
        {
            result.push_back('(');
            result.push_back(s[slow]);
            if(s[fast] >= '0' && s[fast] <= '9')
            {
                result.push_back(s[fast]);
            }
            else
            {
                result.push_back(')');
                result.push_back(s[fast]);
                fast ++;
                slow = fast;
            }
            fast ++;
        }
        else
        {
            result.push_back(s[slow]);
            slow ++;
            fast ++;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> vec;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    cout << ysf(n, m) << endl;
    return 0;    
}