class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int earliest = INT_MAX;
        int latest = INT_MIN;
        for(vector<int> x : logs){
            earliest = min(earliest, x[0]);
            latest = max(latest, x[1]);
        }

        vector<int> people(latest-earliest+1, 0);
        for(vector<int> x : logs){
            for(int i = x[0]; i<x[1]; i++){
                people[i-earliest]++;
            }
        }

        int year = INT_MAX;
        int resu = INT_MIN;
        for(int i = 0; i<people.size(); i++){
            if(people[i]>resu){
                resu = people[i];
                year = i+earliest;
            }else if (people[i]==resu){
                if(i+earliest<year){
                    year = i+earliest;
                }
            }
        }

        return year;
    }
};