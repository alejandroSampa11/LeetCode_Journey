class Solution {
public:

    void permutation(vector<vector<int>>& resu, vector<bool> used, vector<int> path, vector<int>& nums){
        if(path.size() == nums.size()){
            resu.push_back(path);
            return;
        }
        for(int i = 0; i<nums.size(); i++){
            if(used[i]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            permutation(resu, used, path, nums);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> resu;
        vector<bool> used (n, false);
        vector<int> path;
        permutation(resu, used, path, nums);

        // for(vector<int> x : resu){
        //     for(int y : x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        return resu;
    }
};