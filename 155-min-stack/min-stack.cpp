class MinStack {
public:
    stack<vector<int>> s;
    MinStack() {
        
    }
    
    void push(int val) {
        int m = val;
        if(!s.empty()){
            m = min(m, s.top()[1]);
        }
        s.push({val, m});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top()[0];
    }
    
    int getMin() {
        return s.top()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */