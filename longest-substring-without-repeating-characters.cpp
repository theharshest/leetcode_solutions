class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int final=0;
        int curr=0;
        int n=s.length();
        string curr_str;
        
        for(int i=0; i<n; i++)
        {
            int pos=curr_str.find(s[i]);
            curr_str+=s[i];
            
            if(pos!=string::npos)
            {
                string tmp=curr_str.substr(pos+1);
                curr=tmp.length();
                curr_str=tmp;
            }
            else
                curr++;
            
            final=max(final, curr);
        }
        
        return final;
    }
};
