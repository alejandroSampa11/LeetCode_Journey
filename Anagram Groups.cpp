class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> res;
        vector<vector<string>> res2;
        for(int i =0;i<strs.size();i++){
            string var =  strs[i];
            sort(var.begin(),var.end());
            res[var].push_back(strs[i]);
        }
        for (const auto& [key, value] : res) {
        res2.push_back(value);
        }
        return res2;
    }
};
