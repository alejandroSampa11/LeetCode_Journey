class Solution {
public:

    map<pair<int,int>, bool> memo;
    unordered_map<int,bool> rocks;
    bool dp(vector<int>& stones, int unit, int rock){
        if(!rocks.count(rock)) return false; 
        if(memo.count({rock, unit})) return memo[{rock, unit}];
        if(unit<=0) return false;
        if(rock>stones.back()) return false;
        if(rock == stones.back()) return true;
        memo[{rock, unit}] = dp(stones, unit, rock+unit) || dp(stones, unit-1, rock+unit) || dp(stones, unit+1, rock+unit);
        return memo[{rock, unit}];
    }

    bool canCross(vector<int>& stones) {
        for(int x : stones){
            rocks[x] = true;
        }
        return dp(stones, 1, 0);
    }
};