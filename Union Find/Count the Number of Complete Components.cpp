class Solution {
public:

    int findParent(int node, vector<int>& parents){
        if(parents[node] == node) return node;
        return parents[node] = findParent(parents[node], parents);
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents(n);
        vector<int> edgesC(n, 0);
        vector<int> nodes(n,1);

        for(int i = 0; i<n; i++){
            parents[i] = i;
        }

        for(auto e : edges){
            int root1 = findParent(e[0], parents);
            int root2 = findParent(e[1], parents);
            if(root1 != root2){
                parents[root1] = root2;
                nodes[root2] += nodes[root1];
                edgesC[root2] += edgesC[root1]+1;
            }else{
                edgesC[root1]++;
            }
        }

        int resu = 0;
        for(int i = 0; i<n; i++){
            if(parents[i] == i){
                int edge = edgesC[i];
                int node = nodes[i];
                if(edge == (node*(node-1))/2){
                    resu++;
                }
            }
        }

        return resu;

    }
};