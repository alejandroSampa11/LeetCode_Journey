class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>numeros;
        int eliminados = 0;
        int i = 0;
        while (i < nums.size()) {
            if (numeros[nums[i]] < 2) {
            numeros[nums[i]]++;
            i++;
        } else {
            int inicio = i;
            int fin = i;
            cout << "INICIO " << inicio << endl;
            while (fin + 1 < nums.size() && nums[fin] == nums[fin + 1]) {
                fin++;
            }
            cout << "FIN " << fin << endl;
            int diff = fin - inicio + 1;
            for (int j = fin + 1; j < nums.size(); j++) {
                nums[j - diff] = nums[j];
            }
            eliminados += fin - inicio + 1;
            nums.resize(nums.size() - diff);
        }
}
        for(auto& x : nums){
            cout<<x<<endl;
        }
        cout<<"ELIMIANDOS "<<eliminados<<endl;

        return nums.size();
    }
};