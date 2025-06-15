class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>resu;
        vector<int>tempLeft;
        vector<int>tempRight;
        tempLeft.push_back(1);
        tempRight.push_back(1);
        int left = 1;
        int right = 1;
        for(int i = 1;i<nums.size();i++){
            left=tempLeft[i-1]*nums[i-1];
            tempLeft.push_back(left);
        }

        int j = 1;
        for(int i = nums.size()-2;i>=0;i--){
            right = tempRight[j-1]*nums[i+1];
            tempRight.push_back(right);
            j++;
        }

        reverse(tempRight.begin(),tempRight.end());
        
        for(int i = 0;i<nums.size();i++){
            resu.push_back(tempLeft[i]*tempRight[i]);
        }
        
        return resu;
    }
};