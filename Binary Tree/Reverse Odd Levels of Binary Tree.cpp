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

    void travel(TreeNode* nodeLeft, TreeNode* nodeRight, int level){
        if(nodeLeft == NULL || nodeRight == NULL) return;

        if(level%2 != 0){
            int aux = nodeLeft->val;
            nodeLeft->val = nodeRight->val;
            nodeRight->val = aux;  
        }

        travel(nodeLeft->left, nodeRight->right, level+1);
        travel(nodeLeft->right, nodeRight->left, level+1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {

        travel(root->left, root->right, 1);
        return root;
    }
};