class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        unordered_map<int, vector<pair<int,int>>> nodes;
        for(vector<int> x : edges){
            nodes[x[0]].push_back({x[1], x[2]});
            nodes[x[1]].push_back({x[0], x[2]});
        }

        vector<vector<int>> dist(passingFees.size(), vector<int>(maxTime+1, INT_MAX));
        dist[0][0] = passingFees[0];
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({passingFees[0],0,0});
        
        while(!pq.empty()){
            auto [cost, node, time] = pq.top(); pq.pop();
            if(cost>dist[node][time]) continue;
            if(time>maxTime) continue;

            for(auto [nodeV, timeV] : nodes[node]){
                int newTime = time + timeV;
                int newCost = cost + passingFees[nodeV];
                if(newTime <= maxTime && newCost < dist[nodeV][newTime]){
                    dist[nodeV][newTime] = newCost;
                    pq.push({newCost, nodeV, newTime});
                }

            }
        }

        int resu = INT_MAX;
        for(int i = 0; i<=maxTime; i++){
            resu = min(dist[passingFees.size()-1][i], resu);
        }

        return (resu == INT_MAX ? -1 : resu); 
        
    }
};