/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> levelSums;
    void sums(TreeNode* root, TreeNode* parent, int depth) {
        if (!root) return;

        if (depth >= levelSums.size())
            levelSums.push_back(0);
        levelSums[depth] += root->val;

        sums(root->left, root, depth + 1);
        sums(root->right, root, depth + 1);
    }

    void replace(TreeNode* root, int childSum, int depth) {
        if (!root) return;

        root->val = levelSums[depth] - childSum;
        int nextChildSum = 0;

        if(root->left) nextChildSum+=root->left->val;
        if(root->right) nextChildSum+=root->right->val;

        replace(root->left, nextChildSum, depth + 1);
        replace(root->right, nextChildSum, depth + 1);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        sums(root, NULL, 0);
        replace(root, 0, 0);
        root->val = 0;
        return root;
    }
};