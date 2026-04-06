class Solution {
public:
    bool dfs(int node, int colorNumber, vector<vector<int>>& nodes, vector<int>& color) {
        color[node] = colorNumber;

        for(int next : nodes[node]){
            if(color[next] == colorNumber) return false;

            if(color[next] == 0){
                if(!dfs(next, -colorNumber, nodes, color)) return false;
            }    
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> nodes(n+1);
        for (int i = 0; i < dislikes.size(); i++) {
            nodes[dislikes[i][0]].push_back(dislikes[i][1]);
            nodes[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        vector<int> color(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (color[i] != 0)
                continue;
            if(!dfs(i, 1, nodes, color)) return false;
        }
        return true;
    }
};