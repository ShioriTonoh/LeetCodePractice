class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        unique.push_back(x);
    }
    
    int pop() {
        int res = unique.back();
        unique.pop_back();
        return res;
    }
    
    int top() {
        return unique.back();
    }
    
    bool empty() {
        return unique.empty();
    }

private:
    deque<int> unique;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */