class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int start = 0;
        int n = nums.size();
        int maxScore = 0;
        set<int> st;
        int temp = 0;
        for(int end = 0; end<n; end++){
            int numero = nums[end];
            if(!st.count(numero)){
                st.insert(nums[end]);
                temp+= nums[end];
            }else{
                while(nums[start] != numero){
                    st.erase(nums[start]);
                    temp-=nums[start];
                    start++;
                }
                start++;
            }
            maxScore = max(maxScore, temp);
        }
        return maxScore;
    }
};