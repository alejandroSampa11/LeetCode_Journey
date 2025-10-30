class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) nums[i] = 0;
            else nums[i] = 1;
            
        }
        int resu = 0;
        int start = 0;
        int temp = 0;
        for(int end = 0; end<nums.size();end++){
            if(nums[end]) temp++;

            while(temp>k){
                if(nums[start]){
                    temp--;
                }
                start++;
            }
            int cont = 0;
            int tempK = temp;
            int tempStart = start;
            while(tempK == k){
                cont++;
                if(nums[tempStart]) tempK--;
                tempStart++;
            }
            resu+=cont;

        }
        return resu;
    }
};