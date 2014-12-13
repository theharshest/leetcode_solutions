class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int m=0;
        
        for(int i=0; i<n; i++)
            if(A[i]==elem)
                m++;
                
        if(m==n)
            return 0;
            
        int k=n-1;
        
        while(A[k]==elem)
            k--;
            
        int l=0, res=n;
        
        while(l<k)
        {
            if(A[l]==elem)
            {
                A[l]=A[k];
                k--;
                while(A[k]==elem)
                    k--;
            }
            l++;
        }
        
        return n-m;
    }
};
