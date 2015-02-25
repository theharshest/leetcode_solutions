class Solution {
public:
    string expandaroundcenter(string s, int c1, int c2, int n)
    {
        while(c1>=0 && c2<n && s[c1]==s[c2])
        {
            c1--;
            c2++;
        }
        
   c1++;
   c2--;

        return s.substr(c1, c2-c1+1);
    }

    string longestPalindrome(string s) {
        int n=s.length();
        int longest=0;  
        string res;
        
        for(int i=0; i<n; i++)
        {
            string s1=expandaroundcenter(s, i, i, n);
            int n1=s1.length();
            
            string s2=expandaroundcenter(s, i, i+1, n);
            int n2=s2.length();
            
            if(n1>n2 && n1>longest)
            {
                res=s1;
                longest=n1;
            }
            else if(n2>n1 && n2>longest)
            {
                res=s2;
                longest=n2;
            }
        }

        return res;
    }
};
