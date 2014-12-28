class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        
        for(int i=0; i<int(tokens.size()); i++)
        {
            string token=tokens[i];
            if(token=="+" || token=="-" || token=="/" || token=="*")
            {
                int num1=stk.top();
                stk.pop();
                int num2=stk.top();
                stk.pop();
                
                if(token=="+")
                    stk.push(num2+num1);
                else if(token=="-")
                    stk.push(num2-num1);
                else if(token=="*")
                    stk.push(num2*num1);
                else
                    stk.push(num2/num1);
            }
            else
            {
                int num=stoi(token);
                stk.push(num);
            }
        }
        
        return stk.top();
    }
};
