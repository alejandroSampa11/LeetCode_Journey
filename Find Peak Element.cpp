class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        int left = 0;
        int right = nums.size()-1;
        if(nums[left]>nums[left+1]){
            return left;
        }
        if(nums[right]>nums[right-1]){
            return right;
        }
        left++;
        right--;
        while(left <= right){
            if(nums[left]>nums[left+1] && nums[left]>nums[left-1]){
                return left;
            }
            if(nums[right]>nums[right-1] && nums[right]>nums[right+1]){
                return right;
            }
            left++;
            right--;
        }
        return 0;
    }
};