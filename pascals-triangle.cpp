class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        vector<int> prev{1};
        
        if(numRows==0)
            return res;
        
        res.push_back(prev);
        if(numRows==1)
            return res;
        
        for(int i=2; i<=numRows; i++)
        {
            vector<int> curr;
            curr.push_back(1);
            for(int j=1; j<i-1; j++)
                curr.push_back(prev[j-1]+prev[j]);
            curr.push_back(1);
            res.push_back(curr);
            prev=curr;
        }
        
        return res;
    }
};
