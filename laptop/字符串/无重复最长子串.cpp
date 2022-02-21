#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string& s)
    {   
        int n = s.size();
        if(n == 0)
        {
            return 0;
        }
        set<char> vec;
        int maxlength = 0;
        int pre_length = 0;
        for(int i = 0; i < n; )
        {
            char c = s[i];
            vec.insert(c);
            if(vec.size() == pre_length) //出现重复
            {
                vec.erase(vec.begin());
                pre_length -= 1;
            }
            else
            {
                pre_length += 1;
                maxlength = max(maxlength, pre_length);
                i++;
            }
            
        }
        return maxlength;
    }
};


int main()
{
    string s;
    cin >> s;
    Solution solu;
    cout << solu.lengthOfLongestSubstring(s) << endl;;
    
    return 0;
}