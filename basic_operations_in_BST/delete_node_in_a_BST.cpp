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

//知道想法但自己寫不出來
//網路上recursive的寫法
TreeNode* deleteNode(TreeNode *root, int key)
{
    if(root)
    {
        //先找到key
        if(root->val > key)
            root->left = deleteNode(root->left, key);
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        //找到key
        else
        {
            //沒有child
            if(!root->left and !root->right)
            {
                delete root;
                return nullptr;
            }
            //有一個child
            else if(!root->left or !root->right)
            {
                TreeNode *tmp = root->left? root->left : root->right;
                delete root;

                return tmp;
            }
            //如果有兩個child，則找左子樹最大的值
            else
            {
                TreeNode *tmp = root->left;
                
                while(tmp->right)
                    tmp = tmp->right;
                
                root->val = tmp->val;
                //recursive刪除node
                root->left = deleteNode(root->left, tmp->val);
            }
        }
    }

    return root;
}