class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n=triangle.size();
        vector<vector<int> > res(n);
        
        res[0]=triangle[0];
        
        for(int i=1; i<n; i++)
        {
            vector<int> tmp(i+1);
            tmp[0]=res[i-1][0]+triangle[i][0];
            tmp[i]=res[i-1][i-1]+triangle[i][i];
            for(int j=1; j<i; j++)
            {
                tmp[j]=min(res[i-1][j], res[i-1][j-1]);
                tmp[j]+=triangle[i][j];
            }
            res[i]=tmp;
        }
        
        return *min_element(res[n-1].begin(), res[n-1].end());
    }
};
