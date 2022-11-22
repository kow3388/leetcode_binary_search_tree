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

TreeNode* searchBST(TreeNode *root, int val)
{
    if(!root)
        return nullptr;
    
    if(root->val == val)
        return root;
    else if(root->val > val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

void inorder(TreeNode *root)
{
    if(!root)
        return;
    
    inorder(root->left);
    cout << root->val << endl;
    inorder(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    TreeNode *ans = searchBST(root, 5);
    inorder(ans);

    return 0;
}