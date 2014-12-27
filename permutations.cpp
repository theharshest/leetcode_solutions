class Solution {
public:
    vector<vector<int> > permuteutil(vector<int> &num, int mini, int maxi)
    {
        if(mini==maxi)
        {
            vector<int> tmp{num[mini]};
            vector<vector<int> > res{tmp};
            return res;
        }
            
        vector<vector<int> > rest=permuteutil(num, mini+1, maxi);
        int first=num[mini];
        
        vector<vector<int> > res;
        
        for(int i=0; i<rest.size(); i++)
        {
            for(int j=0; j<=rest[i].size(); j++)
            {
                vector<int> curr=rest[i];
                curr.insert(curr.begin()+j, first);
                res.push_back(curr);
            }
        }
        
        return res;
    }

    vector<vector<int> > permute(vector<int> &num) {
        int n=num.size();
        return permuteutil(num, 0, n-1);
    }
};
