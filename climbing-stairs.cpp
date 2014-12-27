class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2)
            return n;
        
        int num1=1;
        int num2=2;
        int res=0;
        
        for(int i=3; i<=n; i++)
        {
            res=num1+num2;
            num1=num2;
            num2=res;
        }
        
        return res;
    }
};
