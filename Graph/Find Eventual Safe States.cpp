class Solution {
public:

    bool bfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& visiting){
        visited[node] = true;
        visiting[node] = true;

        for(int x : graph[node]){
            if(!visited[x]){
                if(!bfs(x, graph, visited, visiting)) return false;
            }else if(visiting[x]){
                return false;
            }
        }
        visiting[node] = false;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> resu;
        vector<bool> visited (graph.size(), false);
        vector<bool> visiting (graph.size(), false);
        for(int i = 0; i<graph.size();i++){
            if(bfs(i, graph, visited, visiting)) resu.push_back(i);
        }
        return resu;
    }
};