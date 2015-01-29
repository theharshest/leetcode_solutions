class Solution {
public:
    static bool compr(string a, string b)
    {
        return (a+b)>(b+a);
    }

    string largestNumber(vector<int> &num) {
        vector<string> numstrs;
        int n=num.size();
        
        for(int i=0; i<n; i++)
            numstrs.push_back(to_string(num[i]));
            
        sort(numstrs.begin(), numstrs.end(), compr);
        
        string res;
        
        if(numstrs[0][0]=='0')
            return "0";
        
        for(int i=0; i<n; i++)
            res+=numstrs[i];
            
        return res;
    }
};
