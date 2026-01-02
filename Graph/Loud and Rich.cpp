class Solution {
public:

    void bfs(int node, unordered_map<int,vector<int>>& mp, vector<bool>& visited, vector<int>& quiet, int& mini, int& person){
        visited[node] = true;
        for(auto x : mp[node]){
            if(!visited[x]){
                if(mini> quiet[x]){
                    mini = quiet[x];
                    person = x;
                }
                bfs(x, mp, visited, quiet, mini, person);
            }
        }
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        unordered_map<int,vector<int>> mp;
        vector<int> resu;
        for(vector<int> x : richer){
            mp[x[1]].push_back(x[0]);
        }

        for(int i = 0; i<quiet.size(); i++){
            int mini = quiet[i];
            int person = i;
            vector<bool> visited(quiet.size(), false);
            bfs(i, mp, visited, quiet, mini, person);
            resu.push_back(person);
        }

        return resu;
    }
};