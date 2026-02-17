class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int round = grid[0].size();
        int resu = 0;
        while (round--) {   
            vector<pair<int,int>> values;
            int maxi = 0;
            for (int i = 0; i < grid.size(); i++) {
                priority_queue<pair<int, int>> pq;
                for (int j = 0; j < grid[0].size(); j++){
                    if(grid[i][j] == -1) continue;
                    pq.push({grid[i][j], j});
                }
                auto greater = pq.top();
                grid[i][greater.second] = -1;
                maxi = max(maxi, greater.first);
            }
            resu+= maxi;
        }
        return resu;
    }
};