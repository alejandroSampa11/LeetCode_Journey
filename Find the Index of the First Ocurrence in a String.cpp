class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0;i<haystack.size();i++){
            if(haystack[i]==needle[0]){
                string ext = haystack.substr(i,needle.size());
                if(ext==needle){
                    return i;
                }
            }
        }
        return -1;
    }
};