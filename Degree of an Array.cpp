class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int>dist;
        vector<int>degrees;
        int maximo = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            dist[nums[i]]++;
            if(dist[nums[i]]>maximo){
                maximo = dist[nums[i]];
                degrees.clear();
                degrees.push_back(nums[i]);
            }else if(dist[nums[i]]==maximo){
                degrees.push_back(nums[i]);
            }
        }
        int minimo = INT_MAX;
        for(auto& x : degrees){
            int inicio = 0;
            int fin = nums.size();
            for(int i = 0;i<nums.size();i++){
                if(nums[i] == x){
                    inicio = i;
                    break;
                }
            }
            for(int i = nums.size()-1;i>=inicio;i--){
                if(nums[i] == x){
                    fin = i;
                    break;
                }
            }
            cout<<"INICIO "<<inicio<<endl;
            cout<<"FIN "<<fin<<endl;
            int longi = fin-inicio+1;
            cout<<"LONGG "<<longi<<endl; 
            if(fin-inicio+1<=minimo){
                minimo = min(minimo,fin-inicio+1);
            }
        }

        return minimo;
    }
};