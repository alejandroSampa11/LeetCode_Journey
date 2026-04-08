class Solution {
public:

    int findParent(int node, vector<int>& parents){
        if(parents[node] == node) return node;
        return parents[node] = findParent(parents[node], parents);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parents (n);
        for(int i = 0; i<n; i++){
            parents[i] = i;
        }

        int resu = n;

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(isConnected[i][j] == 1){
                    int root1 = findParent(i, parents);
                    int root2 = findParent(j, parents);
                    if(root1 != root2){
                        parents[root2] = root1;
                        resu--;
                    }
                }
            }
        }
        return resu;

    }
};