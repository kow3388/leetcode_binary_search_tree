#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inordertraversal(TreeNode *root, TreeNode *p, vector<TreeNode*> &inorder)
{
    if(!root)
        return;
    
    inordertraversal(root->left, p, inorder);
    inorder.push_back(root);
    inordertraversal(root->right, p, inorder);
}

TreeNode* inorderSuccessor(TreeNode *root, TreeNode *p)
{
    vector<TreeNode*> inorder;
    inordertraversal(root, p, inorder);

    for(int i = 0; i < inorder.size(); i++)
        if(inorder[i] == p)
            return (i == inorder.size()-1)? nullptr : inorder[i+1];

    return root;
}

//網路上其他的寫法
//因為successor一定是較大的值
TreeNode* inorderSuccessor1(TreeNode *root, TreeNode *p)
{
    TreeNode *ans = nullptr;

    //不是空節點
    while(root)
    {
        //如果現在比p大
        //往左邊找看484有比p大但比root小的值
        if(root->val > p->val)
        {
            ans = root;
            root = root->left;
        }
        //如果現在的值比p小，往右邊找
        else
            root = root->right;
    }

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    root->right = new TreeNode(6);

    TreeNode *ans = inorderSuccessor1(root, root->left->left->left);
    if(!ans)
        cout << "null" << endl;
    else
        cout << ans->val << endl;

    return 0;
}