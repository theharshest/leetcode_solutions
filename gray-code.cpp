class Solution {
public:
    void grayCodehelper(int n, vector<int>& res)
    {
        if(n==1)
            return;
        
        grayCodehelper(n-1, res);
        
        int setbit=1;
        setbit<<=n-1;
        
        for(int i=res.size()-1; i>=0; i--)
            res.push_back(res[i]|setbit);
    }

    vector<int> grayCode(int n) {
        vector<int> res={0};
        
        if(n==0)
            return res;

        res.push_back(1);
        
        grayCodehelper(n, res);
        
        return res;
    }
};
