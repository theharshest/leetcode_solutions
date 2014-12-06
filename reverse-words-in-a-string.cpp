class Solution {
public:
    void reverseWords(string &s) {
        while(s[0]==' ')
            s.erase(s.begin());
        
        if(s!="")
        {
            vector<string> words;
            int len=s.length();
        
            for(int i=0; i<len; i++)
            {
                string tmp="";
                bool f=0;
                while(s[i]!=' ' && i<len)
                {
                    tmp+=s[i];
                    i++;
                    f=1;
                }
                if(f)
                    words.insert(words.begin(), tmp);
            }
        
            s="";
            len=words.size();
            for(int i=0; i<len-1; i++)
            {
                s+=words[i];
                s+=' ';
            }
            s+=words[len-1];
        }
    }
};
