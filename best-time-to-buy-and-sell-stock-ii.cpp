class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> diff;
        int n=prices.size();
        
        for(int i=1; i<n; i++)
            diff.push_back(prices[i]-prices[i-1]);
            
        sort(diff.rbegin(), diff.rend());
        
        int res=0;
        
        for(int i=0; i<n-1; i++)
        {
            if(diff[i]>0)
                res+=diff[i];
            else
                break;
        }
        
        return res;
    }
};
