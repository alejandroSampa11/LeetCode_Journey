class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        q.push(startGene);
        char letters[] = {'A', 'C', 'G', 'T'};
        unordered_set<string> visited;
        visited.insert(startGene);

        int resu = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string gene = q.front();
                q.pop();

                if (gene == endGene)
                    return resu;

                for(int i = 0; i<startGene.size(); i++){
                    char originalChar = gene[i];
                    for(int j = 0; j<4; j++){
                        gene[i] = letters[j];
                        if(find(bank.begin(), bank.end(), gene) != bank.end() && !visited.count(gene)){
                            q.push(gene);
                            visited.insert(gene);
                        }
                    }
                    gene[i] = originalChar;
                }
            }
            resu++;
        }
        return -1;
    }
};