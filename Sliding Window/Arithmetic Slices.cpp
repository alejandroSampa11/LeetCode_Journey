class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> diff(nums.size(), 0);
        if(nums.size() < 3){
            return 0;
        }

        diff[0] = nums[1]-nums[0];
        for(int i = 1; i<nums.size();i++){
            diff[i] = nums[i]-nums[i-1];
        }

        int resu = 0;
        int start = 0;
        int dif = diff[1];
        int cont = 0;
        for(int end = 0; end<nums.size();end++){
            cout<<dif<<endl;
            if(dif != diff[end]){
                // cout<<end<<endl;
                dif = diff[end];
                start = end-1;
                cont = 0;
            }else{
                if(end-start+1>=3){
                    cont++;
                    resu+=cont;
                }
            }
        }
        return resu;
    }
};