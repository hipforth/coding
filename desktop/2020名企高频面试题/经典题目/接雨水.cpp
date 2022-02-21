#include "bits/stdc++.h"

using namespace std;

//双指针解法
/*
1. 接雨水是由左右指针最小值决定
2. 维护两个指针变量left, right和指针的历史最大值leftMax, rightMax
3. 当俩指针吗没相遇时：
    1. 更新leftMax和rightMax
    2. 若height[left] < height[right]， 必定leftMax < rightMax， 此时left处能接到leftMax-height[left]的雨水，left++;
    3. 若height[left] >= height[right], 必定leftMax >= rightMax， right处能接到rightMax-height[right]的雨水，right--;
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right]) {
                ans += leftMax - height[left];
                ++left;
            } else {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};
