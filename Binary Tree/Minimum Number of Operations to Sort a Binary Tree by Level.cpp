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

    int swaps(vector<int>& levelTemp){
        int totalSwaps = 0;
        unordered_map<int, int> pos;
        vector<int> sorted = levelTemp;
        sort(sorted.begin(), sorted.end());

        for(int i = 0; i<levelTemp.size(); i++){
            pos[levelTemp[i]] = i;
        }

        for(int i = 0; i<sorted.size(); i++){
            if(levelTemp[i] != sorted[i]){
                totalSwaps++;

                int correctValue = sorted[i];
                int idxCorrect = pos[correctValue];

                pos[levelTemp[i]] = idxCorrect;

                swap(levelTemp[i], levelTemp[idxCorrect]);

            }
        }
        return totalSwaps;
    }



    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int total = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> levelTemp;
            while(size--){
                auto node = q.front();
                q.pop();

                levelTemp.push_back(node->val);

                if(node->left){
                    q.push(node->left);
                } 
                if(node->right){
                    q.push(node->right);
                } 
            }
            total+= swaps(levelTemp);
        }

        // for(vector<int> x : levels){
        //     for(int y : x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }

        return total;
    }
};