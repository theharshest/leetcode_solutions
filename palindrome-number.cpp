class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        
        int numd=0;
        int y=x;
        
        while(y)
        {
            y/=10;
            numd++;
        }
        
        while(x)
        {
            if(x%10!=x/(int)pow(10.0,float(numd-1)))
                return false;
            x%=(int)pow(10.0,float(numd-1));
            x/=10;
            numd-=2;
        }
        
        return true;
    }
};
