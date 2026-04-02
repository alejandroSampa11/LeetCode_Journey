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

    pair<int,int> travel(TreeNode* root, int &resu) {
        if(!root) return {0,0};

        pair<int,int> left = travel(root->left, resu);
        pair<int,int> right = travel(root->right, resu);

        int sum = left.first + right.first + root->val;
        int numNodes = 1 + left.second + right.second;

        if(sum/numNodes == root->val){
            resu++;
        }

        return {sum, numNodes};
    }

    int averageOfSubtree(TreeNode* root) {
        int resu = 0;
        travel(root, resu);
        return resu;
    }
};