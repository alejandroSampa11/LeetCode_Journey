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
    void dfs(unordered_map<int, char>& abc, TreeNode* root, string word, vector<string>& words) {
        if (!root) return;

        word = abc[root->val]+word;
        if (!root->left && !root->right) {
            words.push_back(word);
        }

        dfs(abc, root->left, word, words);
        dfs(abc, root->right, word, words);
    }

    string smallestFromLeaf(TreeNode* root) {
        unordered_map<int, char> abc;
        vector<string> words;
        char letra = 'a';
        for (int i = 0; i <= 25; i++) {
            abc[i] = letra + i;
        }

        dfs(abc, root, "", words);

        auto it = *min_element(words.begin(), words.end());
        return it;
    }
};