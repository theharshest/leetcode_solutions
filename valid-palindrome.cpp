class Solution {
public:
    bool isPalindrome(string s) {
        string t="";
        
        for(string::iterator it=s.begin(); it!=s.end(); it++)
        {
            bool check1 = *it>='a' && *it<='z';
            bool check2 = *it>='A' && *it<='Z';
            bool check3 = (*it-'0')>=0 && (*it-'0')<=9;
            if(check1 || check2 || check3)
                t+=tolower(*it);
        }
        
        if(t=="")
            return true;

        int i=0;
        int j=t.length()-1;
        
        for(; i<j; i++,j--)
        {
            if(t[i]!=t[j])
                return false;
        }
        
        return true;
    }
};
