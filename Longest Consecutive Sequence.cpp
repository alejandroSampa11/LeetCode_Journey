class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int resu = 1;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++){
            int temp=nums[i];
            int mayor = 1;
            for(int j=i+1;j<nums.size();j++){
                if(temp+1==nums[j]){
                    mayor++;
                    temp++;
                }
            }
            resu = max(mayor,resu); 
        }
        return resu;
    }
};






