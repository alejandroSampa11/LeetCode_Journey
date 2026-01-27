class Solution {
public:

    map<pair<int,int>,bool> memo;
    bool dp(vector<int>& nums, int pos, int suma, int sumaFinal){
        if(memo.count({pos,suma})) return memo[{pos, suma}];
        if(suma==sumaFinal) return true;
        if(pos >= nums.size()) return false;
        if(suma>sumaFinal) return false;

        bool resu = dp(nums, pos+1, suma+nums[pos], sumaFinal);
        if(!resu){
            resu = dp(nums, pos+1, suma, sumaFinal);
        }

        memo[{pos, suma}] = resu;
        return memo[{pos,suma}];
    }   


    bool canPartition(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        for(int x : nums){
            sum+=x;
        }
        if(sum%2 != 0) return false;
        sum/=2;
        return dp(nums, 0, 0, sum);
    }
};