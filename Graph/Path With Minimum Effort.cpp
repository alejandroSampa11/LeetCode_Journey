class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        vector<vector<int>> dist(heights.size(),
                                 vector<int>(heights[0].size(), INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        // DISTANCIA, FILA, COLUMN
        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [effort, fila, columna] = pq.top();
            pq.pop();
            if (effort > dist[fila][columna])
                continue;

            int newStep;
            int newEffort;
            if (columna - 1 >= 0) {
                newStep =
                    abs(heights[fila][columna] - heights[fila][columna - 1]);
                newEffort = max(effort, newStep);
                if (newEffort < dist[fila][columna - 1]) {
                    dist[fila][columna - 1] = newEffort;
                    pq.push({newEffort, fila, columna - 1});
                }
            }
            if (columna + 1 < heights[0].size()) {
                newStep =
                    abs(heights[fila][columna] - heights[fila][columna + 1]);
                newEffort = max(effort, newStep);
                if (newEffort < dist[fila][columna + 1]) {
                    dist[fila][columna + 1] = newEffort;
                    pq.push({newEffort, fila, columna + 1});
                }
            }
            if (fila - 1 >= 0) {
                newStep =
                    abs(heights[fila][columna] - heights[fila - 1][columna]);
                newEffort = max(effort, newStep);
                if (newEffort < dist[fila - 1][columna]) {
                    dist[fila - 1][columna] = newEffort;
                    pq.push({newEffort, fila - 1, columna});
                }
            }
            if (fila + 1 < heights.size()) {
                newStep =
                    abs(heights[fila][columna] - heights[fila + 1][columna]);
                newEffort = max(effort, newStep);
                if (newEffort < dist[fila + 1][columna]) {
                    dist[fila + 1][columna] = newEffort;
                    pq.push({newEffort, fila + 1, columna});
                }
            }
        }

        return dist[heights.size() - 1][heights[0].size() - 1];
    }
};