class Solution {
public:
    bool canJump(vector<int>& nums) {
        int limit = nums[0];
        for(int i = 0; i<=limit; i++){
            if(limit>=nums.size()-1) return true;
            limit = max(limit, i + nums[i]);
        }
        return false;
    }
};