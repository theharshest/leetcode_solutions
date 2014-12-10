class Solution {
public:
    int uniquePaths(int m, int n) {
        int num=n+m-2;
        int den1=max(n-1, m-1);
        int den2=min(n-1, m-1);
        
        long long res=1;
        
        for(int i=num; i>den1; i--)
            res*=(long long)i;
            
        for(int i=1; i<=den2; i++)
            res/=(long long)i;
            
        return int(res);
    }
};
