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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        int level = 0;
        helper(root, level);
        int n = mp.size();
        vector<vector<int> > vec(n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < mp[i].size(); j++)
            {
                vec[i].push_back(mp[i][j]);
            }
        }
        return vec;
    }
private:
    int helper(TreeNode* root, int level)
    {
        if(root == nullptr) return 0;
        mp[level].push_back(root->val);
        helper(root->left, level+1);
        helper(root->right, level+1);
        return 1;
    }
unordered_map<int, vector<int> > mp;  
};
// 2. 广度优先搜索
class Solution1 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> ret;
        if (!root) {
            return ret;
        }
        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            ret.push_back(vector <int> ());
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front(); q.pop();
                ret.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ret;
    }
};

int main()
{

    return 0;
}
