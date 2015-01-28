class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len=s.length();
        vector<bool> validind(len);
        
        for(int i=0; i<len; i++)
        {
            string curr=s.substr(0, i+1);
            if(dict.find(curr)!=dict.end())
                validind[i]=true;
                
            for(int j=i-1; j>=0; j--)
            {
                string curr1=s.substr(j+1, i-j);
                if(validind[j] && dict.find(curr1)!=dict.end())
                    validind[i]=true;
            }
        }
        
        return validind[len-1];
    }
};
