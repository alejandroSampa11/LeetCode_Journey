class Solution {
public:

    int findParent(int node, vector<int>& parents){
        if(parents[node] == node) return node;
        return parents[node] = findParent(parents[node], parents);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> parents(n);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }

        for(const auto& e : edges){
            int root1 = findParent(e[0], parents);
            int root2 = findParent(e[1], parents);
            if(root1 == root2){
                return {e[0], e[1]};
            }else{
                parents[root2] = root1;
            }
        }

        return {};
    }
};