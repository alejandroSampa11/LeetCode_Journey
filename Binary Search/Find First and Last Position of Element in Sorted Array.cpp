class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> resu (2, -1);

        int left = 0; 
        int right = nums.size()-1;

        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                resu[0] = mid;
                right = mid-1;
            }
            if(nums[mid] > target){
                right= mid-1;
            }
            if(nums[mid] < target){
                left= mid+1;
            }
        }

        left = 0;
        right = nums.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                resu[1] = mid;
                left = mid+1;
            }
            if(nums[mid] > target){
                right= mid-1;
            }
            if(nums[mid] < target){
                left= mid+1;
            }
        }
        
        return resu;

    }
};