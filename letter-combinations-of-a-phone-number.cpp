class Solution {
public:
    void getcombs(vector<string>& res, string curr, vector<string>& allstrs, int n, int ind)
    {
        if(int(curr.length())==n)
        {
            res.push_back(curr);
            return;
        }
            
   for(int j=0; j<allstrs[ind].length(); j++)
        getcombs(res, curr+allstrs[ind][j], allstrs, n, ind+1);
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> numtostr;
        numtostr['2']="abc";
        numtostr['3']="def";
        numtostr['4']="ghi";
        numtostr['5']="jkl";
        numtostr['6']="mno";
        numtostr['7']="pqrs";
        numtostr['8']="tuv";
        numtostr['9']="wxyz";
        
        vector<string> allstrs;
        int n=digits.length();
        
        for(int i=0 ;i<n; i++)
            allstrs.push_back(numtostr[digits[i]]);
            
        vector<string> res;

        if(n==0)
            return res;

        getcombs(res, "", allstrs, n, 0);

for(int i=0; i<res.size(); i++)
{
cout<<res[i]<<endl;
}
        
        return res;
    }
};
