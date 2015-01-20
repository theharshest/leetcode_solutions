class Solution {
public:
    void generateParenthesisutil(int left, int right, string curr, vector<string> &res)
    {
        if(right==0)
        {
            res.push_back(curr);
            return;
        }
        
        if(left>0)
            generateParenthesisutil(left-1, right, curr+'(', res);
        
        if(right>left)
            generateParenthesisutil(left, right-1, curr+')', res);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        generateParenthesisutil(n, n, curr, res);
        
        return res;
    }
};
