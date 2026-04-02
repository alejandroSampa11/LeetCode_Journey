class Solution {
public:
    bool dfs(int node, int parent, vector<vector<pair<int, int>>> & nodes, vector<bool>& currentColors, vector<int>& resu, vector<bool>& targetColors) {
        for (auto [child, idx] : nodes[node]) {
            if (child == parent)
                continue;
            if (dfs(child, node, nodes, currentColors,resu, targetColors)) {
                currentColors[node] = !currentColors[node];
                resu.push_back(idx);
            }
        }
        return currentColors[node] != targetColors[node];
    }

    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start,
                             string target) {
        // nodes[x] = {{hijo, indice de arista}};
        vector<vector<pair<int, int>>> nodes(n);
        vector<bool> currentColors(start.size(), false);
        vector<bool> targetColors(target.size(), false);
        vector<int> resu;
        int diff = 0;

        for (int i = 0; i < start.size(); i++) {
            if (start[i] == '1')
                currentColors[i] = true;
            if (target[i] == '1')
                targetColors[i] = true;
            if (currentColors[i] != targetColors[i])
                diff++;
        }

        if (diff % 2 != 0)
            return {-1};

        for (int i = 0; i < n-1; i++) {
            nodes[edges[i][0]].push_back({edges[i][1], i});
            nodes[edges[i][1]].push_back({edges[i][0], i});
        }
        
        if(dfs(0, -1,nodes, currentColors, resu,targetColors)) return {-1};

        sort(resu.begin(), resu.end());
        return resu;

    }
};