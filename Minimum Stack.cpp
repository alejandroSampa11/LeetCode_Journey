class MinStack {
public:
    vector<int>num;

    MinStack() {
    }
    
    void push(int val) {
        num.insert(num.begin(),val);
    }
    
    void pop() {
        num.erase(num.begin());
    }
    
    int top() {
        return num[0];
    }
    
    int getMin() {
        return *min_element(num.begin(),num.end());
    }
};
