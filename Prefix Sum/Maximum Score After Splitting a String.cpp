class Solution {
public:
    int maxScore(string s) {
        vector<int> vc(s.size() + 1, 0);
        int cont = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                vc[i + 1] = vc[i] + 1;
            } else {
                vc[i + 1] = vc[i];
            }
        }
        
        int resu = 0;
        int start = 1;
        int end = vc.size()-1;
        for(int mid = start; mid<vc.size()-1; mid++){
            int zeros = (mid-start+1)-(vc[mid] - vc[start-1]);
            int ones = vc[end] - vc[mid];
            resu = max(resu, zeros+ones);
        }

        return resu;
    }
};