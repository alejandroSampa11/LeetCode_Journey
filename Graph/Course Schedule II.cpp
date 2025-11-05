class Solution {
public:


    bool dfs(int node, unordered_map<int,vector<int>>& nodes, vector<bool>& visited, vector<bool>& visiting, vector<int>& result){
        visited[node] = true;
        visiting[node] = true;
        for(auto x : nodes[node]){
            if(!visited[x]){
                if(!dfs(x, nodes, visited, visiting, result)) return false;
            }else if(visiting[x]){
                return false;
            }
        }

        visiting[node] = false;
        result.push_back(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        vector<bool> visited(numCourses, false);
        vector<bool> visiting(numCourses, false);
        vector<int> results;
        for(vector<int> x : prerequisites){
            mp[x[1]].push_back(x[0]);
        }

        for(int i = 0; i<numCourses; i++){
            if(!visited[i]){
                if(!dfs(i,mp, visited, visiting, results)) return {};
            }
        }

        reverse(results.begin(), results.end());
        return results;
    }
};