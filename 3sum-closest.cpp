class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int n=num.size();
        int ressum=INT_MAX;
        int res=0;
        
        for(int i=0; i<n-2; i++)
        {
            int low=i+1;
            int high=n-1;
            
            while(low<high)
            {
                if(abs(num[i]+num[low]+num[high]-target)<ressum)
                {
                    res=num[i]+num[low]+num[high];
                    ressum=abs(num[i]+num[low]+num[high]-target);
                }   
                
                if(num[i]+num[low]+num[high]>target)
                    high--;
                else if(num[i]+num[low]+num[high]<target)
                    low++;
                else
                    return num[i]+num[low]+num[high];
            }
        }
        
        return res;
    }
};
