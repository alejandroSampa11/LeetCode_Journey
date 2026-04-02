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

    TreeNode* build(vector<int>&nums, int left, int right){
        if(left>right) return NULL;

        auto it = max_element(nums.begin()+left, nums.begin()+right+1);
        int maxIdx = distance(nums.begin(), it);

        TreeNode* root = new TreeNode(*it);
        root->left = build(nums, left, maxIdx-1);
        root->right = build(nums, maxIdx+1, right);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
};