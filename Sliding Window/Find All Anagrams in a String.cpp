class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> need(26,0);
        vector<int> have(26,0);
        vector<int> resu;

        for(char x : p){
            need[x-'a']++;
        }
        
        for(int i = 0; i<s.size(); i++){
            have[s[i]-'a']++;

            if(i>=p.size()){
                have[s[i-p.size()] - 'a']--;
            }

            if(i >= p.size()-1 && have==need){
                resu.push_back(i+1-p.size());
            }
        }
        return resu;
    }
};