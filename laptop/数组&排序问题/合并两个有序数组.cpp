#include <bits/stdc++.h>

using namespace std;


class Solver{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        vector<int> nums;
        int i = 0, j = 0;
        for( ; i < m, j < n; )
        {
            if(nums1[i] <= nums2[j])
            {
                nums.push_back(nums1[i]);
                i++;
            }
            else
            {
                nums.push_back(nums[j]);
                j++;
            }    
        }
        if(i < m && j == n)
        {
            nums.push_back(nums1[i]);
        }
        if(j < n && i == m)
        {
            nums.push_back(nums[j]);
        }
        nums1 = nums;

    }
};


int main()
{

    return 0;
}

