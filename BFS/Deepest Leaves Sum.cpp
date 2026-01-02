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

    void bfs(TreeNode* root, vector<vector<int>>& levels, int level){
        if(root == NULL) return;

        if(level >= levels.size()){
            levels.push_back({});
        }

        levels[level].push_back(root->val);
        bfs(root->left, levels, level+1);
        bfs(root->right, levels, level+1);
    }

    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>> levels;
        int resu = 0;
        bfs(root, levels, 0);

        for(int x : levels[levels.size()-1]){
            resu+=x;
        }
        
        return resu;
    }
};