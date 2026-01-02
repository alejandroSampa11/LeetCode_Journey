class Solution {
public:

    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<tuple<int, int, int,int>, vector<tuple<int, int, int,int>>, greater<tuple<int, int, int,int>>> pq;
        vector<vector<vector<int>>> time(moveTime.size(),vector<vector<int>> (moveTime[0].size(), vector<int>(2, INT_MAX)));
        time[0][0][0] = 0;
        pq.push({0, 0, 0, 0});

        while (!pq.empty()) {
            auto [timeNode, nodeX, nodeY, state] = pq.top();
            pq.pop();
            if (timeNode > time[nodeX][nodeY][state])
                continue;

            int newTime;
            int newState = 1-state;
            if (nodeX - 1 >= 0) {
                newTime = max(timeNode, moveTime[nodeX - 1][nodeY]) + (!state ? 1 : 2);
                if (newTime < time[nodeX - 1][nodeY][newState]) {
                    time[nodeX - 1][nodeY][newState] = newTime;
                    pq.push({newTime, nodeX - 1, nodeY, newState});
                }
            }
            if (nodeX + 1 < moveTime.size()) {
                newTime = max(timeNode, moveTime[nodeX + 1][nodeY]) + (!state ? 1 : 2);
                if (newTime < time[nodeX + 1][nodeY][newState]) {
                    time[nodeX + 1][nodeY][newState] = newTime;
                    pq.push({newTime, nodeX + 1, nodeY, newState});
                }
            }

            if (nodeY - 1 >= 0) {
                newTime = max(timeNode, moveTime[nodeX][nodeY - 1]) + (!state ? 1 : 2);
                if (newTime < time[nodeX][nodeY - 1][newState]) {
                    time[nodeX][nodeY - 1][newState] = newTime;
                    pq.push({newTime, nodeX, nodeY - 1, newState});
                }
            }
            if (nodeY + 1 < moveTime[0].size()) {
                newTime = max(timeNode, moveTime[nodeX][nodeY + 1]) + (!state ? 1 : 2);
                if (newTime < time[nodeX][nodeY + 1][newState]) {
                    time[nodeX][nodeY + 1][newState] = newTime;
                    pq.push({newTime, nodeX, nodeY + 1, newState});
                }
            }
        }

        return min(time[time.size()-1][time[0].size()-1][0], time[time.size()-1][time[0].size()-1][1]);
    }
};