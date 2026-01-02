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

    void dfs(TreeNode* root, TreeNode* parent, int& suma){
        if(root == NULL) return;

        if(parent->val % 2 == 0){
            if(root->left != NULL){
                suma+= root->left->val;
            }
            if(root->right != NULL){
                suma+= root->right->val;
            }
        }
        dfs(root->left, root, suma);
        dfs(root->right, root, suma);
    }

    int sumEvenGrandparent(TreeNode* root) {
        int suma = 0;
        dfs(root->left, root, suma);
        dfs(root->right, root, suma);
        return suma;
    }
};