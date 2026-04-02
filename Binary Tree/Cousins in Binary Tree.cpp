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

    TreeNode* parent1;
    TreeNode* parent2;
    int depth1;
    int depth2;
    void dfs(TreeNode* root, TreeNode* parent, int depth, int node1, int node2){
        if(!root) return;

        if(root->val == node1){
            parent1 = parent;
            depth1 = depth;
        }

        if(root->val == node2){
            parent2 = parent;
            depth2 = depth;
        }

        dfs(root->left, root, depth+1, node1,node2);
        dfs(root->right, root, depth+1, node1,node2);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, NULL, 0,x,y);
        return (depth1 == depth2) && (parent1 != parent2);
    }
};