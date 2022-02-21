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
    bool isSymmetric(TreeNode* root) {

    }
private:
    bool helper(TreeNode* root)
    {
        if(root == nullptr) return true;
        if(root->left == nullptr && root->right == nullptr) return true;
        if(root->left == nullptr && root->right != nullptr) return false;
        if(root->left != nullptr && root->right == nullptr) return false;
        if(root->left != nullptr && root->right != nullptr) 
        {
            if(root->left->val != root->right->val) return false;
            return helper(root->left) && helper(root->right);
        }
    }
};


int main()
{

    return 0;
}
