#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int length_l = maxDepth(root->left);
        int length_r = maxDepth(root->right);
        return max(length_l, length_r) + 1;
    }
};


int main()
{

    return 0;
}
