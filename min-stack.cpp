class MinStack {
public:
    stack<int> s1;
    stack<int> s2;
    
    void push(int x) {
        if(s1.empty())
        {
            s1.push(x);
            s2.push(x);
        }
        else if(x<=s2.top())
        {
            s1.push(x);
            s2.push(x);
        }
        else
        {
            s1.push(x);
        }
    }

    void pop() {
        if(s1.top() == s2.top())
        {
            s1.pop();
            s2.pop();
        }
        else
        {
            s1.pop();
        }
    }

    int top() {
        if(!s1.empty())
            return s1.top();
        return NULL;
    }

    int getMin() {
        if(!s2.empty())
            return s2.top();
        return NULL;
    }
};
