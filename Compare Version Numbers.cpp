class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> num1;
        vector<int> num2;
        string num = "";
        for (int i = 0; i < version1.size(); i++) {
            if (version1[i] == '.' && num != "") {
                int numerillo = stoi(num);
                num1.push_back(numerillo);
                num = "";
            } else {
                num += version1[i];
            }
        }
        int numerillo = stoi(num);
        num1.push_back(numerillo);

        num = "";
        for (int i = 0; i < version2.size(); i++) {
            if (version2[i] == '.' && num != "") {
                int numerillo = stoi(num);
                num2.push_back(numerillo);
                num = "";
            } else {
                num += version2[i];
            }
        }
        int numerillo2 = stoi(num);
        num2.push_back(numerillo2);

        int maxi = max(num1.size(), num2.size());
        for (int i = 0; i < maxi; i++) {
            if (i >= num1.size()) {
                if (0 > num2[i]) {
                    return 1;
                } else if (0 < num2[i]) {
                    return -1;
                } else {
                    continue;
                }
            } else if (i >= num2.size()) {
                if (num1[i] > 0) {
                    return 1;
                } else if (num1[i] < 0) {
                    return -1;
                } else {
                    continue;
                }
            } else {
                if (num1[i] > num2[i]) {
                    return 1;
                } else if (num1[i] < num2[i]) {
                    return -1;
                } else {
                    continue;
                }
            }
        }

        return 0;
    }
};