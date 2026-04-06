class Solution {
public:

    bool dfs(int node, int colorNumber, vector<vector<int>>& graph, vector<int>& color){
        color[node] = colorNumber;
        for(int next : graph[node]){
            if(color[next] == colorNumber) return false;
            if(color[next] == 0){
                if(!dfs(next, -colorNumber, graph, color)) return false;
            }
        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color (n, 0);

        for(int i = 0; i<n; i++){
            if(color[i] != 0) continue;
            if(!dfs(i, 1, graph, color)) return false;
        }
        
        return true;
    }
};