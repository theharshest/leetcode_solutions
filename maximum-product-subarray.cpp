class Solution {
public:
    int maxProduct(int A[], int n) {
        int maxi=A[0], mini=A[0], res=A[0];
        
        for(int i=1; i<n; i++)
        {
            int tmpmaxi=maxi;
            
            maxi=max(max(maxi*A[i], mini*A[i]), A[i]);
            mini=min(min(tmpmaxi*A[i], mini*A[i]), A[i]);
            
            res=max(res, maxi);
        }
        
        return res;
    }
};
