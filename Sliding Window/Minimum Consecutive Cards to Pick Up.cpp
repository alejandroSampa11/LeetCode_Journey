class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> mp;
        int start = 0;
        int resu = INT_MAX;

        for(int end = 0; end<cards.size(); end++){
            mp[cards[end]]++;
            
            if(mp[cards[end]] == 2){
                while(mp[cards[end]]>=2){
                    resu = min(resu, end-start+1);
                    mp[cards[start]]--;
                    start++;
                }
            }
        }
        return resu == INT_MAX ? -1 : resu;
    }
};