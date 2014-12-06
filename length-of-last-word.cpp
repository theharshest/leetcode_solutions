class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(*s=='\0')
            return 0;
            
        const char *t=s;
        
        while(*s==' ')
        {
            s++;
            t++;
        }
        
        while(*t!='\0')
        {
            t++;
            if((*t>='a' && *t<='z') || (*t>='A' && *t<='Z'))
                s=t;
        }
        
        int n=0;
        
        while((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))
        {
            s--;
            n++;
        }
        
        return n;
    }
};
