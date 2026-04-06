class Solution {
public:
    int findParent(int node, vector<int>& parents) {
        if (parents[node] == node)
            return node;
        return parents[node] = findParent(parents[node], parents);
    }

    int reachableNodes(int n, vector<vector<int>>& edges,
                       vector<int>& restricted) {
        vector<int> parents(n);
        vector<int> isRestricted(n, false);

        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
        for (int node : restricted) {
            isRestricted[node] = true;
        }

        for (auto e : edges) {
            if (isRestricted[e[0]] || isRestricted[e[1]])
                continue;
            int root1 = findParent(e[0], parents);
            int root2 = findParent(e[1], parents);
            if (root1 != root2) {
                parents[root1] = root2;
            }
        }

        int resu = 0;
        int rootZero = findParent(0, parents);
        for(int x : parents){
            if(findParent(x, parents) == rootZero){
                resu++;
            }
        }

        return resu;
    }
};