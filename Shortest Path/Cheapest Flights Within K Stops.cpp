class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> nodes;
        for(vector<int> x : flights){
            nodes[x[0]].push_back({x[1], x[2]});
        }
        vector<vector<int>> costs (n, vector<int>(k+1, INT_MAX));
        costs[src][0] = 0;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({0,src,0});

        while(!pq.empty()){
            auto [cost, node, stop] = pq.top(); pq.pop();
            if(cost>costs[node][stop]) continue;
            if(stop > k) continue;
            if(node == dst) return cost;

            for(auto [nodeV, costV] : nodes[node]){
                int newCost = cost + costV;
                int newStop = stop;
                if(nodeV != dst){
                    newStop = stop+1;
                }
                if(newStop <= k && newCost<costs[nodeV][newStop]){
                    costs[nodeV][newStop] = newCost;
                    pq.push({newCost, nodeV, newStop});
                }
            }
        }

        return -1;
    }
};