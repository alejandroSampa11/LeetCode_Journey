class Solution {
public:

    void backtracking(vector<int>& nums, vector<int>& path, vector<vector<int>>& resu, int start){
        resu.push_back(path);
        for(int i = start; i<nums.size(); i++){
            if(i>start && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            backtracking(nums, path, resu, i+1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> resu;
        vector<int> path;
        sort(nums.begin(), nums.end());
        backtracking(nums, path, resu, 0);
        return resu;
    }
};