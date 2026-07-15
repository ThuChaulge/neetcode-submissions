class MinStack {
public:
    stack<int> s;
    stack<int> sOfMin;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (sOfMin.empty()) {
            sOfMin.push(val);
        } else {
            sOfMin.push(min(val, sOfMin.top()));
        }
    }
    
    void pop() {
        s.pop();
        sOfMin.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return sOfMin.top();
    }
};
