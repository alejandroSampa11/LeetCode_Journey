class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        unordered_map<char,int> have;

        for(char c : t){
            need[c]++;
        }
        int haveCount = 0;
        int needCount = need.size();

        int start = 0;
        int startResu = 0;
        int leng = INT_MAX;

        for(int end = 0; end<s.size(); end++){
            char letra = s[end];
            have[letra]++;

            if(need.count(letra) && have[letra] == need[letra]){
                haveCount++;
            }

            while(haveCount == needCount){
                if(end-start+1 < leng){
                    startResu = start;
                    leng = end-start+1;
                }
                char letraS = s[start];
                have[letraS]--;
                if(need.count(letraS) && have[letraS]<need[letraS]){
                    haveCount--;
                }
                start++;
            }
        }

        return leng == INT_MAX ? "" : s.substr(startResu,leng);
        
    }
};