class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(), greater<int>());
        int maximo = 0;
        for(int i = 1;i<nums.size()-1;i++){
            if(nums[i-1]<(nums[i]+nums[i+1])){
                maximo = max((nums[i-1]+nums[i]+nums[i+1]),maximo);                
            }
        }
        return maximo;
    }
};