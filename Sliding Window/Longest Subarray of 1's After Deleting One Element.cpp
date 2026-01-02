class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> resu(2,0);
        int start = 0;
        int resul = 0;
        for(int end = 0; end<nums.size(); end++){
            resu[nums[end]]++;

            while(resu[0]>1){
                resu[nums[start]]--;
                start++;
            }

            resul = max(resul, end-start);
        }
        return resul;
    }
};