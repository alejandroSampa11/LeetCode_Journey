class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>pila;
        for(auto& x : tokens){
            if(x == "+" || x == "-" || x == "*" || x == "/"){
                int num1 = pila.top();
                pila.pop();
                int num2 = pila.top();
                pila.pop();
                int resu = 0;
                if (x == "+") {
                    resu = num2 + num1;
                } else if (x == "-") {
                    resu = num2 - num1;
                } else if (x == "*") {
                    resu = num2 * num1;
                } else if (x == "/") {
                    resu = num2 / num1; 
                }
                pila.push(resu);
            }else{
                int num = stoi(x);
                pila.push(num);
            }
        }
        return pila.top();
    }
};
