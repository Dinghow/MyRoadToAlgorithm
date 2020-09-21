#include<stack>
#include<algorithm>

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk, stk_min;
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        if(stk_min.empty()){
            stk_min.push(x);
        }
        else{
            stk_min.push(min(x, stk_min.top()));
        }
    }
    
    void pop() {
        stk.pop();
        stk_min.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return stk_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */