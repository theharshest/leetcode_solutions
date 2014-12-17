class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int m=strs.size();
        string res="";
        
        if(m==0)
            return res;
        
        int n=strs[0].length();
        
        for(int i=1; i<m; i++)
            n=min(n, int(strs[i].length()));
        
        for(int i=0; i<n; i++)
        {
            bool f=1;
            char c=strs[0][i];
            for(int j=1; j<m; j++)
            {
                if(c!=strs[j][i])
                {
                    f=0;
                    break;
                }
            }
            if(f)
                res+=c;
            else
                break;
        }
        
        return res;
    }
};
