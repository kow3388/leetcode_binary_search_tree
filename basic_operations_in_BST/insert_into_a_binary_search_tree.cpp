#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* insertIntoBST(TreeNode *root, int val)
{
    TreeNode *new_n = new TreeNode(val);

    if(!root)
        return new_n;

    TreeNode *curr = root;
    
    while(curr)
    {
        if(curr->val > val)
        {
            if(!curr->left)
            {
                curr->left = new_n;
                break;
            }
            else
                curr = curr->left;
        }
        else
        {
            if(!curr->right)
            {
                curr->right = new_n;
                break;
            }
            else
                curr = curr->right;
        }
    }

    return root;
}