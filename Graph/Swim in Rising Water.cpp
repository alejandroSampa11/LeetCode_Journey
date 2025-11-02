class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> dist(grid.size(),
                                 vector<int>(grid[0].size(), INT_MAX));
        dist[0][0] = grid[0][0];
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        pq.push({dist[0][0], 0, 0});

        while (!pq.empty()) {
            auto [time, fila, columna] = pq.top();
            pq.pop();

            if (time > dist[fila][columna])
                continue;

            int newTime;
            if (columna - 1 >= 0) {
                newTime = max(time, grid[fila][columna - 1]);
                if (newTime < dist[fila][columna - 1]) {
                    dist[fila][columna - 1] = newTime;
                    pq.push({newTime, fila, columna - 1});
                }
            }
            if (columna + 1 < grid[0].size()) {
                newTime = max(time, grid[fila][columna + 1]);
                if (newTime < dist[fila][columna + 1]) {
                    dist[fila][columna + 1] = newTime;
                    pq.push({newTime, fila, columna + 1});
                }
            }
            if (fila - 1 >= 0) {
                newTime = max(time, grid[fila-1][columna]);
                if (newTime < dist[fila-1][columna]) {
                    dist[fila-1][columna] = newTime;
                    pq.push({newTime, fila-1, columna});
                }
            }
            if (fila + 1 < grid.size()) {
                 newTime = max(time, grid[fila+1][columna]);
                if (newTime < dist[fila+1][columna]) {
                    dist[fila+1][columna] = newTime;
                    pq.push({newTime, fila+1, columna});
                }
            }
        }

        // for(vector<int> x : grid){
        //     for(int y : x){
        //         cout<<y<<",";
        //     }
        //     cout<<endl;
        // }

        return dist[grid.size()-1][grid[0].size()-1];
    }
};