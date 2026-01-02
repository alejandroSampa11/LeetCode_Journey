class Solution {
public:

    void bfs(unordered_map<string, vector<pair<string,double>>>& nodes, string node, string end, unordered_map<string, bool>& visited, double value, vector<double>& resu){
        if(visited[node]) return;
        visited[node] = true;
        if(node == end){
            resu.push_back(value);
            return;
        }
        for(auto [vari, valu] : nodes[node]){
            bfs(nodes, vari, end, visited, value*valu, resu);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> mp;
        vector<double> resu;
        for(int i = 0; i<equations.size(); i++){
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        for(int i = 0; i<queries.size(); i++){
            if(!mp.count(queries[i][0]) || !mp.count(queries[i][1])){
                resu.push_back(-1);
                continue;
            }
            unordered_map<string, bool> visited;
            bfs(mp, queries[i][0], queries[i][1], visited, 1,resu);
            if(!visited[queries[i][1]]){
                resu.push_back(-1);
            }
        }
        
        return resu;
    }
};