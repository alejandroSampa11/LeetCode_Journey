class Solution {
public:
    void bfs(unordered_map<string, vector<string>>& nodes, string node,
             unordered_map<string, int>& counter, vector<string>& supplies,
             vector<string>& resu) {
        counter[node]--;
        if (counter[node] == 0) {
            resu.push_back(node);
            supplies.push_back(node);
        } else if (counter[node] <= 0) {
            for (auto x : nodes[node]) {
                bfs(nodes, x, counter, supplies, resu);
            }
        }
    }

    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_map<string, vector<string>> nodes;
        vector<string> resu;
        for (int i = 0; i < recipes.size(); i++) {
            for (string ing : ingredients[i]) {
                nodes[ing].push_back(recipes[i]);
            }
        }

        unordered_map<string, int> counter;
        for (int i = 0; i < ingredients.size(); i++) {
            counter[recipes[i]] = ingredients[i].size();
        }

        for (int i = 0; i < supplies.size(); i++) {
            bfs(nodes, supplies[i], counter, supplies, resu);
        }

        return resu;
    }
};