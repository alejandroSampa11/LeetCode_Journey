class Solution {
public:

    map<pair<int,int>, int> memo;
    int dp(vector<int>& stones, int pos, int suma, int sumaFinal){
        if(memo.count({pos, suma})) return memo[{pos, suma}];
        if(suma>sumaFinal) return INT_MIN;
        if(pos == stones.size()) return suma;

        int res = max(dp(stones, pos+1, suma+stones[pos], sumaFinal), dp(stones, pos+1, suma, sumaFinal));

        memo[{pos, suma}] = res;
        return memo[{pos,suma}];
    }

    int lastStoneWeightII(vector<int>& stones) {
        int sumaFinal = 0;
        for(int x : stones){
            sumaFinal+=x;
        }
        int sumaDp;
        sumaDp = sumaFinal/2;
        int dpValue = dp(stones,0, 0,sumaDp);
        return sumaFinal - (2*dpValue);
    }
};