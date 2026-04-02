class Solution {
public:

    bool dfs(int node, vector<vector<int>>& nodes, vector<int>& resu, vector<bool>& visited, vector<bool>& visiting){
        visited[node] = true;
        visiting[node] = true;

        for(int x : nodes[node]){
            if(!visited[x]){
                if(!dfs(x, nodes,resu, visited, visiting)) return false;
            }else if(visiting[x]){
                return false;
            }
        }
        visiting[node] = false;
        resu.push_back(node);
        return true;
    }

    vector<int> getSorted (int k, vector<vector<int>>& conditions){
        vector<vector<int>> nodes(k + 1);
        for(vector<int> x : conditions){
            nodes[x[0]].push_back(x[1]);
        }
        vector<int> resu;
        vector<bool> visited (k+1, false);
        vector<bool> visiting (k+1, false);

        for(int i = 1; i<=k; i++){
            if(visited[i]) continue;
            if(!dfs(i, nodes,resu, visited, visiting)) return {};
        }
        reverse(resu.begin(), resu.end());
        return resu;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> row = getSorted(k, rowConditions);
        vector<int> col = getSorted(k, colConditions);
        
        if(row.empty() || col.empty()) return {};
        
        unordered_map<int,int> posR;
        unordered_map<int,int> posC;

        for(int i = 0; i<k ; i++){
            posR[row[i]] = i; 
            posC[col[i]] = i; 
        }

        vector<vector<int>> resu (k, vector<int>(k,0));
        for(int i = 1;i<=k; i++){
            resu[posR[i]][posC[i]] = i;
        }
        
        return resu;
    }
};