class Solution {
public:

    void backtracking(vector<int> path, int start, int len, vector<vector<int>>& resu, vector<int>& nums){
        resu.push_back(path);
        for(int i = start; i<len; i++){
            path.push_back(nums[i]);
            backtracking(path, i+1, len, resu, nums);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> resu;
        vector<int> path;
        backtracking(path, 0, nums.size(), resu, nums);
        return resu;
    }
};x