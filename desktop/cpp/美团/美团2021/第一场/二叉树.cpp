#include <bits/stdc++.h>

using namespace std;

struct TwoTree
{   
    int val;
    TwoTree* left;
    TwoTree* right;

    TwoTree() : val(0), left(nullptr), right(nullptr) {}

    TwoTree(int _val, TwoTree* _left, TwoTree* _right)
            : val(_val), left(_left), right(_right) {}
};

TwoTree* two_tree(TwoTree* head)
{
    if(head == nullptr) return nullptr;
    two_tree(head->left);
    cout << head->val << endl;
    two_tree(head->right);

    return nullptr;
}


int main()
{
    
    return 0;    
}