class Solution {
public:
    void move(char value, pair<int, int>& par) {
        switch (value) {
        case 'U':
            par.second++;
            break;
        case 'D':
            par.second--;
            break;
        case 'R':
            par.first++;
            break;
        case 'L':
            par.first--;
            break;
        }
    }

    void moveReverse(char value, pair<int, int>& par) {
        switch (value) {
        case 'U':
            par.second--;
            break;
        case 'D':
            par.second++;
            break;
        case 'R':
            par.first--;
            break;
        case 'L':
            par.first++;
            break;
        }
    }

    int distinctPoints(string s, int k) {
        pair<int, int> resu = {0, 0};
        for (int i = 0; i < s.size(); i++) {
            move(s[i], resu);
        }
        set<pair<int, int>> st;
        int start = 0;
        pair<int, int> temp = {0, 0};
        for (int end = 0; end < s.size(); end++) {
            move(s[end], temp);

            if (end - start + 1 == k) {
                int x = resu.first - temp.first;
                int y = resu.second - temp.second;
                st.insert({x,y});
                moveReverse(s[start], temp);
                start++;
            }
        }
        return st.size();
    }
};