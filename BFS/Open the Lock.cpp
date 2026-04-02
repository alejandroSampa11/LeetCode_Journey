class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        queue<string> q;
        unordered_set<string> visited;
        unordered_set<string> dead(deadends.begin(), deadends.end());
        q.push(start);
        visited.insert(start);
        unordered_map<char, vector<char>> transitions = {
            {'0', {'1', '9'}}, {'1', {'0', '2'}}, {'2', {'1', '3'}},
            {'3', {'2', '4'}}, {'4', {'3', '5'}}, {'5', {'4', '6'}},
            {'6', {'5', '7'}}, {'7', {'6', '8'}}, {'8', {'7', '9'}},
            {'9', {'8', '0'}}};

        if (dead.count(start))
            return -1;

        int resu = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string code = q.front();
                q.pop();
                if (code == target)
                    return resu;

                for (int i = 0; i < 4; i++) {
                    char originalChar = code[i];
                    for (char nextDigit : transitions[originalChar]) {
                        string next = code;
                        next[i] = nextDigit; 
                        if (!visited.count(next) && !dead.count(next)) {
                            q.push(next);
                            visited.insert(next);
                        }
                    }
                }
            }
            resu++;
        }

        return -1;
    }
};