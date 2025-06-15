class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = false;
        bool decreasing = false;
        for(int i = 0; i<nums.size()-1;i++){
            if(!increasing && !decreasing){
                if(nums[i]<nums[i+1]){
                    increasing = true;
                }else if(nums[i]>nums[i+1]){
                    decreasing = true;
                }
            }
            if(increasing && nums[i]>nums[i+1]){
                return false;
            }
            if(decreasing && nums[i]<nums[i+1]){
                return false;
            }
        }
        return true;
    }
};