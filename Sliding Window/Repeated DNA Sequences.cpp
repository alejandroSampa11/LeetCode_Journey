class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        set<string> st;
        vector<string> resu;
        int start = 0;
        int n = s.size();
        string temp = "";
        for(int end = 0; end<n; end++){
            temp+=s[end];
            
            while(end-start+1 >=10){
                mp[temp]++;
                if(mp[temp]>1){
                    st.insert(temp);
                }
                temp.erase(0,1);
                start++;
            }
        }
        for(auto x : st){
            // cout<<x<<endl;
            resu.push_back(x);
        }
        return resu;
    }
};