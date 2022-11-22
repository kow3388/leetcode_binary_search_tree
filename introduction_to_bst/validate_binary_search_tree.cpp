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

bool isValidBST(TreeNode *root, long min, long max)
{
    if(!root)
        return true;
    
    if(root->val <= min or root->val >= max)
        return false;
    else
        return isValidBST(root->left, min, root->val) and isValidBST(root->right, root->val, max);
}

bool isValidBST(TreeNode *root)
{
    return isValidBST(root, LLONG_MIN, LLONG_MAX);
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    bool ans = isValidBST(root);
    cout << ans << endl;

    return 0;
}