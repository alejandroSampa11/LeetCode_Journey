class Solution {
public:

    void backtracking(vector<int>& nums, vector<int>& path, vector<vector<int>>& resu, int start){
        if(path.size()>=2){
            resu.push_back(path);
        }

        unordered_map<int, bool> usedLevel;
        for(int i = start; i<nums.size(); i++){
            if(path.size()>0 && nums[i]<path.back()) continue;
            if(usedLevel[nums[i]]) continue;
            path.push_back(nums[i]);
            usedLevel[nums[i]] = true;
            backtracking(nums, path, resu, i+1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> resu;
        unordered_map<int, bool> usedLevel;
        backtracking(nums, path, resu, 0);
        return resu;
    }
};