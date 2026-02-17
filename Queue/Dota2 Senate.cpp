class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> cola;
        int partR = 0;
        int partD = 0;
        for (char x : senate) {
            x == 'R' ? partR++ : partD++;
            cola.push(x);
        }

        int baneosR = 0;
        int baneosD = 0;

        while (partR > 0 && partD > 0) {
            char actual = cola.front();
            cola.pop();

            if (actual == 'R') {
                if (baneosR > 0) {
                    baneosR--;
                    partR--;
                    continue;
                }
                baneosD++;
                cola.push(actual);
            } else {
                if (baneosD > 0) {
                    baneosD--;
                    partD--;
                    continue;
                }
                baneosR++;
                cola.push(actual);
            }
        }

        return partD == 0 ? "Radiant" : "Dire";
    }
};