#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*lowest common ancestor(LCA)只會有3種情況
1.   lca
    /   \
   p     q

2.  p
     \
      q

3.    q
     /
    p
*/
TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root->val > p->val and root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    
    if(root->val < p->val and root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);

    if(root->val == p->val or root->val == q->val or
       (root->val > p->val and root->val < q->val) or
       (root->val < p->val and root->val > q->val))
        return root;
    
    return nullptr;
}

int main()
{
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode *ans = lowestCommonAncestor(root, root->left->left, root->left->right->left);
    cout << ans->val << endl;

    return 0;
}