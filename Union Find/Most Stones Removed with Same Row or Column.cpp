class Solution {
public:

    int findParents(int node, vector<int>& parents){
        if(parents[node] == node) return node;
        return parents[node] = findParents(parents[node], parents);
    }

    int removeStones(vector<vector<int>>& stones) {
        int offset = 10001;
        vector<int> parents(20002);

        for(int i = 0; i<20002; i++){
            parents[i] = i;
        }

        for(const auto& x : stones){
            int rootR = findParents(x[0], parents);
            int rootC = findParents(x[1]+offset, parents);
            if(rootR != rootC){
                parents[rootR] = rootC;
            }
        }

        unordered_set<int> groups;
        for(const auto& x : stones){
            groups.insert(findParents(x[0], parents));
        }

        return stones.size()-groups.size();
    }
};