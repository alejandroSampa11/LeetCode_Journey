class Solution {
public:



    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int>alp;
        for(int i = 0;i<order.size();i++){
            alp[order[i]]=i;
        }

        for(const auto x : alp){
            cout<<x.first<<" "<<x.second<<endl;
        }

        for(int i = 0; i<words.size()-1;i++){
            string var1 = words[i];
            string var2 = words[i+1];
            bool swapped = false;
            if(var1.size()>var2.size()){
                swap(var1,var2);
                swapped = true;
            }
            for(int j = 0; j<var1.size();j++){
                if(!swapped){
                    if(j == var1.size()-1 && alp[var1[j]] == alp[var2[j]]){
                        break;
                    }
                    if(alp[var1[j]] < alp[var2[j]]){
                        break;
                    }
                    
                    if(alp[var1[j]] == alp[var2[j]]){
                        continue;
                    }
                    if(alp[var1[j]] > alp[var2[j]]){
                        return false;
                    }

                }else{
                    if(j == var1.size()-1 && alp[var1[j]] == alp[var2[j]]){
                        return false;
                    }
                    if(alp[var1[j]] > alp[var2[j]]){
                        break;
                    }
                    if(alp[var1[j]] == alp[var2[j]]){
                        continue;
                    }
                    if(alp[var1[j]] < alp[var2[j]]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};