#include <bits/stdc++.h>

using namespace std;


class Solver{
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size();
        int m = nums2.size();
        int length = 0, maxLength = 0;
        for(int i = 0; i < n; i++)
        {
            length = 0;
            for(int j = i; j < n; j++)
            {
                if(nums1[length] != nums2[j])
                {
                    
                }
            }
        }
    }
};


int main()
{

    return 0;
}

