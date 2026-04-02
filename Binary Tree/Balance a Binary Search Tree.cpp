/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void inorder(TreeNode* root, vector<int> &nums){
        if(!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    TreeNode* build(vector<int> nums, int left, int right){
        if(left>right) return NULL;
        int mid = left + (right - left) / 2;

        TreeNode* node = new TreeNode(nums[mid]);
        node->left = build(nums, left, mid-1);
        node->right = build(nums, mid+1, right);
        return node;

    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        return build(nums, 0, nums.size()-1);
    }
};