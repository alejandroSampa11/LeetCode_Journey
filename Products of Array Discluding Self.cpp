class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1;
        vector<int> resu;
        for(int i = 0;i<nums.size();i++){
            total*=nums[i];
        }
        for(int i = 0;i<nums.size();i++){
            int temp=1;
            for(int j = 0;j<nums.size();j++){
                if(i==j){
                    continue;
                }
                if(nums[j]==0){
                    temp=0;
                    break;
                }
                temp*=nums[j];
            }
            resu.push_back(temp);
        }
        return resu;
    }
};
