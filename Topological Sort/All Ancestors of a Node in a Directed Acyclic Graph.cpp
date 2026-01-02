class Solution {
public:
    void dfs(int node, int startNode, unordered_map<int, vector<int>>& mp,
             vector<bool>& visited, vector<int>& results) {
        if (visited[node])
            return;
        visited[node] = true;
        for (int x : mp[node]) {
            dfs(x, startNode, mp, visited, results);
        }
        if (node != startNode)
            results.push_back(node);
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> resu;

        for (vector<int> x : edges) {
            mp[x[1]].push_back(x[0]);
        }

        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            vector<int> results;
            dfs(i, i, mp, visited, results);
            reverse(results.begin(), results.end());
            sort(results.begin(), results.end());
            resu.push_back(results);
        }
        return resu;
    }
};