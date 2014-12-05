class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0 || n==1)
            return n;
        else
        {
            int len=n;
            int x1=0, x2=1;
            
            while(x2!=len)
            {
                while(A[x1]==A[x2])
                {
                    x2++;
                    n--;
                    if(x2==len)
                        return n;
                }
                A[x1+1]=A[x2];
                x1++;
                x2++;
            }
        }
        
        return n;
    }
};
