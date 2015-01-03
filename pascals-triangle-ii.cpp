class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res={1};
        
        if(rowIndex==0)
            return res;
        else if(rowIndex==1)
        {
            res.push_back(1);
            return res;
        }
        else
        {
            res.push_back(1);
            for(int i=2; i<=rowIndex; i++)
            {
                for(int j=0; j<i-1; j++)
                {
                    res[j]=res[j]+res[j+1];
                }
                res.insert(res.begin(), 1);
            }
        }
        
        return res;
    }
};
