class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        int start = 0;
        int sum = 0;
        vector<int> window;
        vector<int> resu;
        for(int end = 0; end<n; end++){
            window.push_back(nums[end]);
            if(end-start+1 == k){
                bool flag = true;
                for(int i = 1; i<k; i++){
                    if(window[i-1] >= window[i] || window[i-1] != window[i]-1){
                        flag = false;
                        break;
                    }
                }
                if(flag) resu.push_back(window[k-1]);
                else resu.push_back(-1);
                window.erase(window.begin(), window.begin()+1);
                start++;
            }
        }
        return resu;
    }
};