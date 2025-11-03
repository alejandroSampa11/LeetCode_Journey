class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        auto maxi = max_element(nums.begin(), nums.end());
        int left = 1;
        int right = *maxi;
        int resu = 0;
        while(left<=right){
            int mid = left + (right-left) / 2;
            int sum = 0;
            for(int x : nums){
                if(x%mid==0){
                    sum+=(x/mid);
                }else{
                    sum+=(x/mid)+1;
                }
            }
            if(sum<=threshold){
                resu=mid;
                right = mid-1;
            }
            if(sum>threshold){
                left = mid+1;
            }
        }
        return resu;
    }
};