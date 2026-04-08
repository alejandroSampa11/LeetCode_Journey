class Solution {
public:

    int findParent(int node, vector<int>& parents){
        if(parents[node] == node) return node;
        return parents[node] = findParent(parents[node], parents);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parents(n);
        for(int i = 0; i<n; i++){
            parents[i] = i;
        }

        int cables = 0;
        int laptopsIsolated = n;
        for(const auto&  x : connections){
            int root1 = findParent(x[0], parents);
            int root2 = findParent(x[1], parents);
            if(root1 != root2){
                parents[root2] = root1;
                laptopsIsolated--;
            }else{
                cables++;
            }
        }

        int cablesNeeded = laptopsIsolated-1;
        return cables>=cablesNeeded ? cablesNeeded : -1;
    }
};