class Solution {
public:
    void subsetsutil(vector<vector<int> > &res, vector<int> curr, vector<int> S)
    {
        if(S.size()==0)
        {
            res.push_back(curr);
            return;
        }
        
        vector<int> tmp(curr);
        tmp.push_back(S[0]);
        S.erase(S.begin());
        subsetsutil(res, tmp, S);
        subsetsutil(res, curr, S);
    }

    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> curr;
        
        sort(S.begin(), S.end());
        subsetsutil(res, curr, S);

        return res;
    }
};
