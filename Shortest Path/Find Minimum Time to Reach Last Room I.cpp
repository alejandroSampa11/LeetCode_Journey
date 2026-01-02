class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        vector<vector<int>> time(moveTime.size(),vector<int>(moveTime[0].size(), INT_MAX));
        time[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});


        while (!pq.empty()) {
            auto [timeNode, nodeX, nodeY] = pq.top();
            pq.pop();
            if (timeNode > time[nodeX][nodeY])
                continue;

            int newTime;
            if (nodeX - 1 >= 0){
                newTime = max(timeNode, moveTime[nodeX-1][nodeY])+1;
                if (newTime < time[nodeX - 1][nodeY]) {
                    time[nodeX - 1][nodeY] = newTime;
                    pq.push({newTime, nodeX - 1, nodeY});
                }
            }
            if (nodeX + 1 < moveTime.size()) {
                newTime = max(timeNode, moveTime[nodeX+1][nodeY])+1;
                if (newTime < time[nodeX + 1][nodeY]) {
                    time[nodeX + 1][nodeY] = newTime;
                    pq.push({newTime, nodeX + 1, nodeY});
                }
            }

            if (nodeY - 1 >= 0) {
                newTime = max(timeNode, moveTime[nodeX][nodeY-1])+1;
                if(newTime<time[nodeX][nodeY-1]){
                    time[nodeX][nodeY-1] = newTime;
                    pq.push({newTime, nodeX, nodeY-1});
                }
            }
            if (nodeY + 1 < moveTime[0].size()) {
                newTime = max(timeNode, moveTime[nodeX][nodeY+1])+1;
                if(newTime<time[nodeX][nodeY+1]){
                    time[nodeX][nodeY+1] = newTime;
                    pq.push({newTime, nodeX, nodeY+1});
                }
            }
        }

        return time[time.size()-1][time[0].size()-1];
    }
};