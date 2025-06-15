class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int numNegativos = 0;
        int sumaTotal = 0;
        for(int x : nums){
            if(x<0){
                numNegativos++;
            }
            sumaTotal+=x;
        }

        if(numNegativos==0){
            if(nums[0]==0){
                return sumaTotal;
            }

            if(k%2==0){
                return sumaTotal;
            }else{
                return sumaTotal - (nums[0]*2);
            }
        }else {
            if(numNegativos == k){
                int contador = 0;
                int sum = 0;
                for(int i = 0;i<nums.size();i++){
                    if(contador<k){
                        nums[i] = abs(nums[i]);
                        contador++;
                    }   
                    sum+=nums[i];
                }
                return sum;
            }else if(numNegativos<=k){
                int contador = 0;
                int sum = 0;
                bool cero = false;
                for(int i = 0;i<nums.size();i++){
                    if(contador<numNegativos){
                        nums[i] = abs(nums[i]);
                        contador++;
                    }
                    if(nums[i]==0){
                        cero = true;
                    }   
                    sum+=nums[i];
                }
                int restantes = k-numNegativos;
                if(restantes % 2 == 0){
                    return sum;
                }else{
                    if(cero){
                        return sum;
                    }else{
                        sort(nums.begin(),nums.end());
                        sum-=(nums[0]*2);
                        return sum;
                    }
                }
            }else if(numNegativos>k){
                bool cero = false;
                int sum2 = 0;
                 for(int i = 0;i<nums.size();i++){
                    sum2+=nums[i];
                }

                    int contador = 0;
                    for(int i = 0;i<nums.size();i++){
                        cout<<"NUM "<<nums[i]<<endl;
                        if(contador<k){
                            nums[i] = abs(nums[i]);
                            sum2+= (nums[i]*2);
                            contador++;
                        }
                    }
                    return sum2;
                
            }
        }

        return 0;
        
    }
};