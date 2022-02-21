#include <bits/stdc++.h>

using namespace std;



int search(vector<int>& nums, int target)
{   
    int n = nums.size();
    if(n == 0) return -1;
    int left = 0, right = n - 1;
    while((right - left) > 1)
    {
        int middle = (left + right) / 2;
        if(target == nums[middle]) return middle;
        if(target > nums[middle]) left = middle;
        if(target < nums[middle]) right = middle;
    }
    if(nums[left] == target) return left;
    if(nums[right] == target) return right;
    return -1;
}

int main()
{

    return 0;
}