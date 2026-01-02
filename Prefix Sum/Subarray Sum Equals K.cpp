class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sum(nums.size()+1, 0);
        for(int i = 1; i<sum.size(); i++){
            sum[i] = sum[i-1] + nums[i-1];  
        }

        map<int,int> val;
        val[0] = 1;

        int resu = 0;
        for(int start = 1; start<sum.size(); start++){
            int buscar = sum[start]-k;
            if(val[buscar]>0){
                resu+=val[buscar];
            }
            val[sum[start]]++;
        }

        return resu;
    }
};