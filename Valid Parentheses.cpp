class Solution {
public:
    bool isValid(string s) {
        stack<char>pila;
        for(auto& x : s){
            if(pila.empty()){
                pila.push(x);
            }
            else if(x == '(' || x == '[' || x == '{'){
                pila.push(x);
            }else{
                if(x==')' && pila.top() == '('){
                    pila.pop();
                }else if(x==']' && pila.top() == '['){
                    pila.pop();
                }else if(x=='}' && pila.top() == '{'){
                    pila.pop();
                }else{
                    pila.push(x);
                }
            }
        }
        
        return pila.empty();
        
    }
};
