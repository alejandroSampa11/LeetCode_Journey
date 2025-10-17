class Solution {
public:

    void buildGraph(unordered_map<int,vector<int>>& graph, vector<int>& manager){
        for(int i = 0; i<manager.size(); i++){
            if(manager[i] == -1) continue;
            graph[manager[i]].push_back(i);
        }
    }

    void dfs(unordered_map<int,vector<int>>& graph, int headID, vector<int>& informTime, int total, int& maxi){
        maxi = max(total, maxi); 
        for(int vecino : graph[headID]){
            dfs(graph, vecino, informTime,total+informTime[vecino],maxi);
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> graph;
        buildGraph(graph, manager);
        int total = informTime[headID];
        int maxi = total;
        dfs(graph, headID, informTime, total,maxi);
        return maxi; 
    }
};