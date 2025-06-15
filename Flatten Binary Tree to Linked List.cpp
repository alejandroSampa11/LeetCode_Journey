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
    void preorden(TreeNode* root, vector<int>& orden) {
        if (root) {
            orden.push_back(root->val);
            preorden(root->left, orden);
            preorden(root->right, orden);
        }
    }

    void flatten(TreeNode* root) {
        if (!root)
            return;
        vector<int> orden;
        preorden(root, orden);
        root->left = nullptr;
        TreeNode* temp = root;
        for (int i = 1; i < orden.size(); i++) {
            temp->right = new TreeNode(orden[i]);
            temp = temp->right;
        }
    }
};