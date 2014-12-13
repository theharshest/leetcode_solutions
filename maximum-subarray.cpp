class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n==0)
            return 0;
            
        int sum=0;

        int maxi=*max_element(A, A+n);
        int mini=*min_element(A, A+n);
        
        if((maxi<0 && mini<0))
            return maxi;
        
        int res=0;
        int curr=0;
        
        for(int k=0; k<n; k++)
        {
            if(curr+A[k]<0)
                curr=0;
            else
                curr+=A[k];
            res=max(res, curr);
        }
        
        return res;
    }
};
