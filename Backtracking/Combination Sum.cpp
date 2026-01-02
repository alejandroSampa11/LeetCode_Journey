class Solution {
public:

    void backtracking(vector<int>& candidates, int target, vector<vector<int>>& resu, vector<int> path ,int sum, set<vector<int>>& st){
        if(sum == target){
            sort(path.begin(), path.end());
            if(st.find(path) == st.end()){
                st.insert(path);
                resu.push_back(path);
            }
            return;
        }

        for(int i = 0; i<candidates.size(); i++){
            if(sum+candidates[i] > target) continue;
            path.push_back(candidates[i]);
            backtracking(candidates, target, resu, path, sum+candidates[i], st);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> resu;
        set<vector<int>> st;
        vector<int> path;
        backtracking(candidates, target, resu, path, 0, st);
        
        return resu;    
    }
};