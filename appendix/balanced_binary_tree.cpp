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

int height(TreeNode *root)
{
    if(!root)
        return 0;
    
    int lh = height(root->left);
    int rh = height(root->right);

    if(lh == -1 or rh == -1 or abs(lh - rh) > 1)
        return -1;
    
    return max(lh, rh) + 1;
}

bool isBalanced(TreeNode *root)
{
    if(!root)
        return true;
    
    return (height(root) == -1)? false : true;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);

    bool ans = isBalanced(root);
    cout << ans << endl;

    return 0;
}