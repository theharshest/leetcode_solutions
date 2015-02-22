class Solution {
public:
    bool ispalindrome(string s)
    {
        int low=0;
        int high=s.length()-1;
        
        while(low<high)
        {
            if(s[low]!=s[high])
                return false;

            low++;
            high--;
        }
        
        return true;
    }

    void partitionutil(vector<vector<string>>& res, vector<string> curr, string s, int start)
    {
        if(start==int(s.length()))
        {
            res.push_back(curr);
            return;
        }

        for(int i=1; i<=s.length()-start; i++)
        {
            string tmp=s.substr(start, i);
            if(ispalindrome(tmp))
            {
                curr.push_back(tmp);
                partitionutil(res, curr, s, start+i);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        partitionutil(res, curr, s, 0);

        return res;
    }
};
