class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i=m-1, j=n-1, k=m+n-1;
        
        for(; j>=0 && i>=0;)
        {
            if(A[i]>B[j])
            {
                A[k]=A[i];
                i--;
                k--;
            }
            else
            {
                A[k]=B[j];
                j--;
                k--;
            }
        }
        
        while(j>=0)
        {
            A[k]=B[j];
            j--;
            k--;
        }
    }
};
