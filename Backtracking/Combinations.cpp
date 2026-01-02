class Solution {
public:

    void backtracking(int start, vector<int> path, vector<vector<int>>& resu, int k, int n){
        if(path.size() == k){
            resu.push_back(path);
            return;
        }

        for(int i = start; i<=n; i++){
            path.push_back(i);
            backtracking(i+1, path, resu,k, n);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> resu;
        backtracking(1, path, resu, k, n);
        return resu;
    }
};