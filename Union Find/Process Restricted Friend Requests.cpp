class Solution {
public:
    int findParent(int node, vector<int>& parents) {
        if (parents[node] == node)
            return node;
        return parents[node] = findParent(parents[node], parents);
    }

    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<int> parents(n);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }

        vector<bool> resu;

        for (auto request : requests) {
            int root1 = findParent(request[0], parents);
            int root2 = findParent(request[1], parents);
            if (root1 == root2) {
                resu.push_back(true);
                continue;
            }

            bool canConnect = true;
            for (auto restri : restrictions) {
                int rootR1 = findParent(restri[0], parents);
                int rootR2 = findParent(restri[1], parents);
                if ((rootR1 == root1 && rootR2 == root2) ||
                    (rootR1 == root2 && rootR2 == root1)) {
                    canConnect = false;
                    break;
                }
            }

            if (canConnect) {
                resu.push_back(true);
                parents[root1] = root2;
            } else {
                resu.push_back(false);
            }
        }
        return resu;
    }
};