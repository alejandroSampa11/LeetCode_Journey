class Solution {
public:

    bool canBeShipped(vector<int>& weights, int days, int mid){
        int packageWeight = 0;
        int numDays = 1;
        for(int x : weights){
            if(packageWeight + x > mid){
                numDays++;
                packageWeight = x;
            }else{
                packageWeight+=x;
            }
        }
        return numDays<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0;
        int right = 0;
        for(int x : weights){
            left = max(x, left);
            right+=x;
        }
        
        int resu = 0;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(canBeShipped(weights, days, mid)){
                resu = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return resu;
    }
};