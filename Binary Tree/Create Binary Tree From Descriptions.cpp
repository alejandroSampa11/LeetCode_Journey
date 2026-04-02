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

    void build(map<int, vector<pair<int,int>>>& nodes){

    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> children;

        for(vector<int> d : descriptions){
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            if(!nodeMap.count(parent)){
                nodeMap[parent] = new TreeNode(parent);
            }

            if(!nodeMap.count(child)){
                nodeMap[child] = new TreeNode(child);
            }

            if(isLeft){
                nodeMap[parent]->left = nodeMap[child];
            }else{
                nodeMap[parent]->right = nodeMap[child];
            }
            children.insert(child);
        }

        for(vector<int> d : descriptions){
            int parent = d[0];
            if(children.find(parent) == children.end()) return nodeMap[parent];
        }
        return NULL;
    }
};