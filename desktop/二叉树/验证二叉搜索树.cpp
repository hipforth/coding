#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};
// 
class Solution
{
public:
    bool isValidBST(TreeNode* root)
    {
        int max = LONG_MAX;
        int min = LONG_MIN;
        return _isvalid(root, max, min);
    }
private:
    bool _isvalid(TreeNode* root, long long min, long long max)
    {
        if(root == nullptr) return true;
        if(root->val > min && root->val < max) 
        {
            bool flag_l = _isvalid(root->left, min, root->val);

            bool flag_r = _isvalid(root->right, root->val, max);
            return flag_l && flag_r;
        }
        else
        {
            return false;
        }
    }
};


int main()
{

    return 0;
}
