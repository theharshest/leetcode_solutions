class Solution {
public:
    int trailingZeroes(int n) {
        int zeros=0;
        while(n)
        {
            zeros+=n/5;
            n/=5;
        }
        
        return zeros;
    }
};
