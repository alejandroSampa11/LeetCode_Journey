class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> inDegree (n, 0);
        for(int x : favorite){
            inDegree[x]++;
        }

        queue<int> q;
        vector<int> chainLength (n, 1);
        for(int i = 0; i<n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        } 

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            int next = favorite[curr];
            chainLength[next] = max(chainLength[next], chainLength[curr]+1);
            if(--inDegree[next] == 0) q.push(next);
        }

        int maxCycle = 0;
        int totalPairs = 0;
        vector<bool> visited (n, false);
        for(int i = 0; i<n; i++){
            if(inDegree[i]>0 && !visited[i]){
                int count = 0;
                int curr = i;
                while(!visited[curr]){
                    visited[curr] = true;
                    curr = favorite[curr];
                    count++;
                }
                if(count == 2){
                    totalPairs+= (chainLength[i]+chainLength[favorite[i]]);
                }else{
                    maxCycle = max(maxCycle, count);
                }
            }
        }

        return max(maxCycle, totalPairs);
    }
};