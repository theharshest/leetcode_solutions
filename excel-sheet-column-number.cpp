class Solution {
public:
    int titleToNumber(string s) {
        int res=0;
        int i, j;
        
        for(i=int(s.length())-1, j=0; i>=0; i--, j++)
            res+=(s[i]-'A'+1)*int(pow(26.0, float(j)));
        
        return res;
    }
};
