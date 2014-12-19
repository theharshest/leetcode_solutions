class Solution {
public:
    void sortColors(int A[], int n) {
        int r=0, w=0, b=0;
        
        for(int i=0; i<n; i++)
        {
            if(A[i]==0)
                r++;
            else if(A[i]==1)
                w++;
            else
                b++;
        }
        
        for(int i=0; i<n; i++)
        {
            if(r)
            {
                A[i]=0;
                r--;
            }
            else if(w)
            {
                A[i]=1;
                w--;
            }
            else
                A[i]=2;
        }
    }
};
