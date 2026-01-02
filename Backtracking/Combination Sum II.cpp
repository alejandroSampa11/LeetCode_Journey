    void backtracking(vector<int>& candidates, int target, int start, vector<vector<int>>& resu, vector<int>& path){
        if(target == 0){
            resu.push_back(path);
            return;
        }
        if(target<0){
            return;
        }

        for(int i = start; i<candidates.size(); i++){
            if(target-candidates[i] < 0) continue;
            if(i>start && candidates[i] == candidates[i-1]) continue;
            path.push_back(candidates[i]);
            backtracking(candidates, target-candidates[i], i+1, resu, path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> resu;
        vector<int> path;
        backtracking(candidates, target, 0, resu, path);
        return resu;
    }