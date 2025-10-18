/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void bfs(Node* root, vector<vector<int>>& numbers, int level){
        if(root->children.size() == 0) return;

        if(level>=numbers.size()){
            numbers.push_back({});
        }

        for(auto x : root->children){
            numbers[level].push_back(x->val);
            bfs(x,numbers,level+1);
        }
    }

    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> numbers;
        if(!root) return {};
        numbers.push_back({root->val});
        bfs(root, numbers,1);
        return numbers;
    }
};