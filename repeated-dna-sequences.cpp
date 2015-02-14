class Solution {
public:
    int getintval(string s)
    {
        int res=0;
        for(int i=0; i<s.length(); i++)
        {
            res<<=2;
            if(s[i]=='C')
                res|=1;
            else if(s[i]=='G')
                res|=2;
            else if(s[i]=='T')
                res|=3;
        }
        
        return res;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, bool> hash;
        vector<string> res;
        int len=s.length();
        
        for(int i=0; i<=len-10; i++)
        {
            string tmp=s.substr(i, 10);
            int num=getintval(tmp);
            if(hash.find(num)!=hash.end() && find(res.begin(), res.end(), tmp)==res.end())
                res.push_back(tmp);
            else
                hash[num]=true;
        }
        
        return res;
    }
};
