class Solution {
public:

    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for(int i = 0; i<=maxReach; i++){
            if(maxReach >= nums.size()-1) return true;
            maxReach = max(maxReach, i+nums[i]);
        }
        return false;
    }
};