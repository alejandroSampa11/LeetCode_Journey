class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        unordered_set<int> notAllowed(forbidden.begin(), forbidden.end());
        q.push({0, 0});
        visited.insert({0, 0});
        int maxi = 6000;

        int resu = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [step, action] = q.front();
                q.pop();
                if (step == x)
                    return resu;

                int jumpForward = step + a;
                int jumpBackward = step - b;
                if (!visited.count({jumpForward, 0}) && !notAllowed.count(jumpForward) &&
                    jumpForward <= maxi) {
                    q.push({jumpForward, 0});
                    visited.insert({jumpForward, 0});
                }

                if (!visited.count({jumpBackward, 1}) && !notAllowed.count(jumpBackward) &&
                    action == 0 && jumpBackward >= 0) {
                    q.push({jumpBackward, 1});
                    visited.insert({jumpBackward, 1});
                }
            }
            resu++;
        }

        return -1;
    }
};