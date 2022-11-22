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

//Space: O(n)
class BSTIterator
{
    public:
        BSTIterator(TreeNode* root)
        {
            inorder(root);
        }
        
        int next()
        {
            int tmp = q.front();
            q.pop();

            return tmp;
        }
        
        bool hasNext()
        {
            return !q.empty();
        }
    
    private:
        queue<int> q;

        void inorder(TreeNode *root)
        {
            if(!root)
                return;
            
            inorder(root->left);
            q.push(root->val);
            inorder(root->right);
        }
};

//網路上其他作法
//Space: O(h), h => tree heigh
class BSTIterator1
{
    public:
        BSTIterator1(TreeNode* root)
        {
            pushall(root);
        }
        
        int next()
        {
            //next值就是stack.top()
            //但要把此node的右子樹的最左那條push進stack
            TreeNode *tmp = s.top();
            s.pop();
            pushall(tmp->right);

            return tmp->val;
        }
        
        bool hasNext()
        {
            return !s.empty();
        }
    
    private:
        stack<TreeNode*> s;

        void pushall(TreeNode * root)
        {
            //先把最左邊這條push進stack裡面
            //因為最左邊這條是所有數裡面最小的
            while(root)
            {
                s.push(root);
                root = root->left;
            }
        }
};