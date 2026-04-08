class Solution {
public:
    int findParent(int node, vector<int>& parents) {
        if (parents[node] == node)
            return node;
        return parents[node] = findParent(parents[node], parents);
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> parents(s.size());
        for (int i = 0; i < s.size(); i++) {
            parents[i] = i;
        }

        for (vector<int> pair : pairs) {
            int root1 = findParent(pair[0], parents);
            int root2 = findParent(pair[1], parents);
            if (root1 != root2) {
                parents[root1] = root2;
            }
        }

        unordered_map<int, vector<char>> letters;
        for (int i = 0; i < s.size(); i++) {
            int root = findParent(i, parents);
            letters[root].push_back(s[i]);
        }

        for (auto& [root, children] : letters) {
            sort(children.begin(), children.end(), greater<char>());
        }

        string resu = "";
        for (int i = 0; i < s.size(); i++) {
            int root = findParent(i, parents);
            resu += letters[root].back();
            letters[root].pop_back();
        }

        return resu;
    }
};