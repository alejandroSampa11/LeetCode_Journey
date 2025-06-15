class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximo = nums[0];
        for(int i = 1;i<nums.size();i++){
            if(nums[i-1]+nums[i]>nums[i]){
                nums[i]+=nums[i-1];
            }
            maximo= max(maximo, nums[i]);
        }

        maximo = max(maximo,nums[nums.size()-1]);

        return maximo;
    }
};