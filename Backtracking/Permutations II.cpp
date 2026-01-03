class Solution {
public:

    void backtracking(vector<vector<int>>& resu, vector<int>& path, vector<bool>& used, vector<int>& nums){
        if(path.size() == nums.size()){
            resu.push_back(path);
            return;
        }

        for(int i = 0; i<nums.size(); i++){
            if(used[i]) continue;
            if(i>0 && nums[i-1] == nums[i] && !used[i-1]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(resu, path, used, nums);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> resu;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(resu ,path, used,nums);

        return resu;
    }
};