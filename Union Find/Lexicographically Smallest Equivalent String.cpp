class Solution {
public:

    int findParents(int node, vector<int>& parents){
        if(parents[node] == node) return node;
        return parents[node] = findParents(parents[node], parents);
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parents (26, 0);
        for(int i = 0; i<26; i++){
            parents[i] = i; 
        }

        for(int i = 0; i<s1.size(); i++){
            int root1 = findParents(s1[i]-'a', parents);
            int root2 = findParents(s2[i]-'a', parents);

            if(root1 != root2){
                if(root1<root2){
                    parents[root2] = root1;
                }else{
                    parents[root1] = root2;
                }
            }
        }

        string res = "";
        for(char x : baseStr){
            int root = findParents(x-'a', parents);
            res+= (char)(root+'a');
        }
        return res;
    }
};