class Solution {
public:
    void build_prefix(char *needle, vector<int>& prefix)
    {
        prefix.push_back(0);
        int i=1;
        
        while(needle[i]!='\0')
        {
            if(needle[prefix[i-1]]==needle[i])
                prefix.push_back(prefix[i-1]+1);
            else
                prefix.push_back(0);
            i++;
        }
    }

    int strStr(char *haystack, char *needle) {
        vector<int> prefix;
        int n=strlen(needle);
        int m=strlen(haystack);
        
        if(n==0 && m==0)
            return 0;

        build_prefix(needle, prefix);
        
        int i=0, j=0;
        
        while(i<m)
        {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            else if(needle[j]=='\0')
                return i-n;
            else if(j==0)
                i++;
            else
                j=prefix[j-1];
        }
        
        if(needle[j]=='\0')
            return i-n;
        
        return -1;
    }
};
