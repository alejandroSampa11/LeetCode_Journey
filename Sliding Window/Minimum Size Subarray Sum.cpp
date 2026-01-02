class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int sum = 0;
        int length = INT_MAX;
        for(int end = 0; end<nums.size(); end++){
            sum+=nums[end];
            while(sum>=target){
                length = min(length, end-start+1);
                sum-=nums[start];
                start++;
            }
        }
        return length == INT_MAX ? 0 : length; 
    }
};