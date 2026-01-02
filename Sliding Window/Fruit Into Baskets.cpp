class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int start = 0;
        int resu = 0;
        int temp = 0;
        for(int end = 0; end<fruits.size(); end++){
            mp[fruits[end]]++;
            temp++;

            while(mp.size() > 2){
                mp[fruits[start]]--;
                temp--;
                if(mp[fruits[start]] == 0) mp.erase(fruits[start]);
                start++;    
            }
            resu = max(resu, temp);
        }
        return resu;
    }
};