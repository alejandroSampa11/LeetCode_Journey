class Solution {
public:

    void backtracking(string& s, vector<string>& path, vector<string>& resu,int start){
        if(path.size() == 4 && start == s.size()){
            string ip = "";
            for(string x : path){
                ip+=(x+".");
            }
            ip.pop_back();
            resu.push_back(ip);
            return;
        }

        for(int i = start; i<s.size(); i++){
            if(i-start+1 > 3) break;
            string cut = s.substr(start,i-start+1);
            int cutNumber = stoi(cut);
            if(cutNumber<0 || cutNumber>255) break;
            if(cut[0]=='0' && cut.size()>1) break;
            path.push_back(cut);
            backtracking(s, path, resu, i+1);
            path.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> path;
        vector<string> resu;
        backtracking(s, path, resu, 0);
        return resu;
    }
};