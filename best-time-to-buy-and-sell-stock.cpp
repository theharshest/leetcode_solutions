class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> diff;
        int n=prices.size();
        
        for(int i=1; i<n; i++)
            diff.push_back(prices[i]-prices[i-1]);
            
        int tprof=0, cprof=0;
        
        for(int i=0; i<n-1; i++)
        {
            cprof+=diff[i];
            if(cprof<0)
                cprof=0;
            else
                tprof=max(tprof, cprof);
        }
        
        return tprof;
    }
};
