class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends, int id,
                                          int level) {

        queue<int> q;
        for (int x : friends[id]) {
            q.push(x);
        }
        unordered_map<string, int> movies;
        vector<bool> visited(friends.size() + 1, false);
        visited[id] = true;

        int n = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int id = q.front();
                q.pop();
                if (visited[id])
                    continue;
                visited[id] = true;
                if (n == level) {
                    for (int i = 0; i < watchedVideos[id].size(); i++) {
                        movies[watchedVideos[id][i]]++;
                    }
                }
                for (int i = 0; i < friends[id].size(); i++) {
                    if (visited[friends[id][i]])
                        continue;
                    q.push(friends[id][i]);
                }
            }
            n++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> minHeap;
        for (auto [key, val] : movies) {
            minHeap.push({val, key});
        }

        vector<string> resu;
        while(!minHeap.empty()){
            auto [val, key] = minHeap.top();
            minHeap.pop();
            resu.push_back(key);
        }

        return resu;
    }
};