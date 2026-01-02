class Solution {
public:

    int MOD = 1e9+7;

    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>mp;
        vector<long long> ways(n, 0);
        ways[0] = 1;
        // NODO, TIEMPO
        for(vector<int> x : roads){
            mp[x[0]].push_back({x[1], x[2]});
            mp[x[1]].push_back({x[0], x[2]});
        }
        const long long INF = 1e18;
        vector<long long> dist(n, INF);
        dist[0] = 0;
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        // TIEMPO, NODO
        pq.push({0, 0});

        int resu = 1;
        int minimo = INT_MAX;
        while(!pq.empty()){
            auto [time, nodo] = pq.top(); pq.pop();
            if(time>dist[nodo]) continue;

            for(auto [nodoV, timeV] : mp[nodo]){
                long long nuevoTiempo = timeV + time;
                if(nuevoTiempo < dist[nodoV]){
                    ways[nodoV]=ways[nodo];
                    ways[nodoV] %= MOD;
                    dist[nodoV] = nuevoTiempo;
                    pq.push({nuevoTiempo, nodoV});
                }else if (nuevoTiempo == dist[nodoV]){
                    ways[nodoV]+=ways[nodo];
                    ways[nodoV] %= MOD;

                }
            }
        }

        return ways[n-1];
    }
};