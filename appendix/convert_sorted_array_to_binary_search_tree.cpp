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

TreeNode* create(vector<int> &nums, int l, int r)
{
    if(l > r)
        return nullptr;
    
    int mid = l + (r-l)/2;

    TreeNode *root = new TreeNode(nums[mid]);
    root->left = create(nums, l, mid-1);
    root->right = create(nums, mid+1, r);

    return root;
}

TreeNode* sortedArrayToBST(vector<int> &nums)
{
    return create(nums, 0, nums.size()-1);
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
    vector<int> nums = {-10,-3,0,5,9};
    TreeNode *root = sortedArrayToBST(nums);

    inorder(root);

    return 0;
}