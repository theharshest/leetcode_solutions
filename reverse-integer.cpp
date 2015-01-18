class Solution {
public:
    int reverse(int x) {
        bool neg=false;
        bool first=true;
        int res=0;
        
        if(x<0)
        {
            neg=true;
            x*=-1;
        }
        
        while(x>0)
        {
            int dig=x%10;
            x/=10;
            if(!first)
            {
                if(res>INT_MAX/10)
                    return 0;
                else
                    res*=10;
            }
            else
                first=false;
            
            if(res>INT_MAX-dig)
                return 0;
            else
                res+=dig;
        }
        
        if(neg)
            res*=-1;
        
        return res;
    }
};
