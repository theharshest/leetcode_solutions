class Solution {
public:
    int sqrtutil(int low, int high, int x)
    {
        if(low+1==high)
        {
            if(x/high<high)
                return low;
            else
                return high;
        }
        
        int mid=(low+high)/2;
        if(x/mid==mid)
            return mid;
        else if(x/mid<mid)
            return sqrtutil(low, mid, x);
        else
            return sqrtutil(mid, high, x);
    }

    int sqrt(int x) {
        if(x==0 || x==1)
            return x;
        
        if(x==2 || x==3)
            return 1;
        
        return sqrtutil(1, x/2, x);
    }
};
