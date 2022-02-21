#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string longestPalindrome(string& s) {
        int n = s.size();
        //奇数长度
        int start = 0, end = 0;
        for(int i = 0; i < n - 1; i++)
        {
            pair<int, int> LR = helper(string& s, i, i);
            pair<int, int> _LR = helper(string& s, i, i+1);
            
        }
    }
private:
    pair<int, int> helper(string& s, int left, int right)
    {
        if(left <= 0 || right > n-1 || s[left] != s[right])
        {
            return {left, right};
        }
        left --;
        right ++;
        return helper(string& s, left, right);
    }
};

int main()
{
    string ss;
    cin >> ss;
    Solution solu;
    cout << solu.longestPalindrome(ss) << endl;
    return 0;
}