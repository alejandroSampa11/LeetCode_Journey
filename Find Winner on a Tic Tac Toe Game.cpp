class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        map<vector<int>, string> ocupado;
        for (int i = 0; i < moves.size(); i++) {
            if (i % 2 == 0) {
                ocupado[moves[i]] = "X";
            } else {
                ocupado[moves[i]] = "O";
            }
        }

        if (ocupado[{0, 0}] == ocupado[{0, 1}] &&
            ocupado[{0, 1}] == ocupado[{0, 2}] && ocupado[{0, 2}] != "") {
            if (ocupado[{0, 0}] == "X")
                return "A";
            return "B";
        }

        if (ocupado[{1, 0}] == ocupado[{1, 1}] &&
            ocupado[{1, 1}] == ocupado[{1, 2}] && ocupado[{1, 2}] != "") {
            if (ocupado[{1, 0}] == "X")
                return "A";
            return "B";
        }

        if (ocupado[{2, 0}] == ocupado[{2, 1}] &&
            ocupado[{2, 1}] == ocupado[{2, 2}] && ocupado[{2, 1}] != "") {
            if (ocupado[{2, 0}] == "X")
                return "A";
            return "B";
        }

        if (ocupado[{0, 0}] == ocupado[{1, 0}] &&
            ocupado[{1, 0}] == ocupado[{2, 0}] && ocupado[{1, 0}] != "") {
            if (ocupado[{0, 0}] == "X")
                return "A";
            return "B";
        }

        if (ocupado[{0, 1}] == ocupado[{1, 1}] &&
            ocupado[{1, 1}] == ocupado[{2, 1}] && ocupado[{0, 1}] != "") {
            if (ocupado[{0, 1}] == "X")
                return "A";
            return "B";
        }

        if (ocupado[{0, 2}] == ocupado[{1, 2}] &&
            ocupado[{1, 2}] == ocupado[{2, 2}] && ocupado[{0, 2}] != "") {
            if (ocupado[{0, 2}] == "X")
                return "A";
            return "B";
        }

        if(ocupado[{0,0}] == ocupado[{1,1}] && ocupado[{1,1}] == ocupado[{2,2}] && ocupado[{0, 0}] != ""){
            if (ocupado[{0, 0}] == "X")
                return "A";
            return "B";
        }

        if(ocupado[{0,2}] == ocupado[{1,1}] && ocupado[{1,1}] == ocupado[{2,0}] && ocupado[{0, 2}] != ""){
            if (ocupado[{0, 2}] == "X")
                return "A";
            return "B";
        }

        if(moves.size() == 9){
            return "Draw";
        }

        return "Pending";
    }
};