class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        res = res|(n&1);
        
        for(int i=0; i<31; i++)
        {
            n = n>>1;
            res = res<<1;
            res = res|(n&1);
        }
        
        return res;
    }
};
