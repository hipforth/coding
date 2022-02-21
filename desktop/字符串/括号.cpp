#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


class Solver{
public:
    bool isValid(string& s)
    {
        int n = s.size();
        if(n % 2 != 0) return false;
        unordered_map<char, int> mp{
            {'(', 1}, {'[', 2}, {'{', 3},
            {')', 4}, {']', 5}, {'}', 6}
        };
        stack<char> _stack;
        for(auto x : s)
        {
            if(_stack.empty()) 
            {
                _stack.push(x);
                continue;
            }
            if(mp[x] <= 3)
            {
                _stack.push(x);
                continue;
            }
            char c = _stack.top();
            if(mp[c] == (mp[x] - 3))
            {
                _stack.pop();
            }
            else
            {
                return false;
            }
        }
        if(_stack.empty()) return true;
        else return false;

    }
};


int main()
{

    return 0;
}