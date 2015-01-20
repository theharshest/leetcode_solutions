class Solution {
public:
    void combineutil(int n, int k, vector<vector<int> > &res, vector<int> curr, int start)
    {
        if(int(curr.size())==k)
        {
            res.push_back(curr);
            return;
        }
        
        for(int i=start; i<=n; i++)
        {
            curr.push_back(i);
            combineutil(n, k, res, curr, i+1);
            curr.pop_back();
        }
    }

    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> curr;
        
        combineutil(n, k, res, curr, 1);
        
        return res;
    }
};
