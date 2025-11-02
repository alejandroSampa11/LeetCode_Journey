class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        int maxCities = INT_MAX;
        int city = 0;
        int numeros = n;
        while (numeros--) {
            // CREAR LA LISTA DE ADYACENCIA ( NODO -> NODO, TIEMPO)
            unordered_map<int, vector<pair<int, int>>> nodes;
            for (vector<int> x : edges) {
                nodes[x[0]].push_back({x[1], x[2]});
                nodes[x[1]].push_back({x[0], x[2]});
            }

            vector<int> dist(n, INT_MAX);
            dist[numeros] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>,
                           greater<pair<int, int>>>
                pq;
            pq.push({0, numeros});

            while (!pq.empty()) {
                auto [time, node] = pq.top();
                pq.pop();
                if (time > dist[node])
                    continue;

                for (auto [nodeV, timeV] : nodes[node]) {
                    int newTime = time + timeV;
                    if (newTime < dist[nodeV]) {
                        dist[nodeV] = newTime;
                        pq.push({newTime, nodeV});
                    }
                }
            }

            int reachable = 0;
            for (int x : dist) {
                if(x<= distanceThreshold && x !=0){
                    reachable++;
                }
            }

            if(reachable<maxCities){
                city=numeros;
                maxCities = reachable;
            }else if(reachable == maxCities){
                if(numeros>city){
                    city = numeros;
                    maxCities = reachable;
                }
            }
        }

        return city;
    }
};