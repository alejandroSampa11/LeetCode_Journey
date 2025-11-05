class Solution {
public:

    bool dfs(int node, unordered_map<int,vector<int>>& nodes, vector<bool>& visited, vector<bool>& visiting, vector<int>& results){
        visited[node] = true;
        visiting[node] = true;
        
        for(int x : nodes[node]){
            if(!visited[x]){
                if(!dfs(x, nodes, visited, visiting, results)) return false;
            }else if(visiting[x]){
                return false;
            }
        }
        visiting[node] = false;
        results.push_back(node);
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        vector<bool> visited(numCourses, false);
        vector<bool> visiting(numCourses, false);
        vector<int> results;

        // CREAR ARBOL
        for(vector<int> x : prerequisites){
            mp[x[1]].push_back(x[0]);
        }

        // ITERAR POR TODOS LOS NODOS
        for(int i = 0; i<numCourses; i++){
            if(!visited[i]){
                if(!dfs(i, mp, visited, visiting, results)) return false;
            }
        }

        reverse(results.begin(), results.end());
        // for(int x : results){
        //     cout<<x<<", ";
        // }
        // cout<<endl;
        return true;
    }
};