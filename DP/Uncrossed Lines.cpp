class Solution {
public:

    map<pair<int,int>,int> memo;
    int dp(vector<int>& nums1, vector<int>& nums2, int pos1, int pos2){
        if(memo.count({pos1, pos2})) return memo[{pos1, pos2}];
        if(pos1 == nums1.size() || pos2 == nums2.size()) return 0;


        int resu = 0;
        if(nums1[pos1] == nums2[pos2]){
            resu = 1 + dp(nums1, nums2, pos1+1, pos2+1);

        }else{
            int notMatch1 = dp(nums1, nums2, pos1+1, pos2);
            int notMatch2 = dp(nums1, nums2, pos1, pos2+1);
            resu = max(notMatch1, notMatch2);
        }
        return memo[{pos1, pos2}] = resu;
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        return dp(nums1, nums2, 0, 0);
    }
};