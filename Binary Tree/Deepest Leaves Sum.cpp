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

    void travel(TreeNode* root, int& sum, int& maxLevel, int level){
        if(root == NULL) return;

        travel(root->left, sum, maxLevel, level+1);
        travel(root->right, sum, maxLevel, level+1);

        if (root->left == NULL && root->right == NULL) {
        if (level > maxLevel) {
            maxLevel = level;
            sum = root->val;
        } else if (level == maxLevel) {
            sum += root->val;
        }
    }
    }

    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        int maxLevel = 0;
        travel(root,sum, maxLevel,0);
        return sum;
    }
};