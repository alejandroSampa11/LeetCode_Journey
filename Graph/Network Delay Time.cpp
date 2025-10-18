class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> nodes;
        
        for(vector<int> x : times){
            nodes[x[0]].push_back({x[1],x[2]});
        }

        const int INF = 1e9;
        vector<int> dist(n+1, INF);
        dist[k]=0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            auto [len, nod] = pq.top(); pq.pop();
            if(len > dist[nod]) continue;

            for(auto [nodeAd, peso] : nodes[nod]){
                if(dist[nodeAd] > dist[nod] + peso){
                    dist[nodeAd] = dist[nod] + peso;
                    pq.push({dist[nodeAd],nodeAd});
                }
            }
        }

        int mini = 0;
        for(int i = 1; i<dist.size();i++){
            if(dist[i] == INF) return -1;
            mini = max(mini, dist[i]);
        }

        return mini;
        
    }
};