class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>> nodes;
        for(int i = 0; i < edges.size(); i++){
            nodes[edges[i][0]].push_back({edges[i][1], succProb[i]});
            nodes[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }   

        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0, start_node});

        while(!pq.empty()){
            auto [peso, node] = pq.top(); pq.pop();
            if(peso<dist[node]) continue;

            for(auto [nodo, weight] : nodes[node]){
                if(dist[nodo] < dist[node] * weight){
                    dist[nodo] = dist[node] * weight;
                    pq.push({dist[nodo], nodo});
                }
            }
        }

        return dist[end_node];
    }
};