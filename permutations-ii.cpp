class Solution {
public:
    void permuteUniqueutil(vector<vector<int> > &res, vector<int> curr, vector<int> num)
    {
        if(num.size()==0)
        {
            res.push_back(curr);
            return;
        }

        for(int i=0; i<num.size(); i++)
        {
        	if(i>0 && num[i]==num[i-1])
        		continue;

        	vector<int> curr1(curr);
        	vector<int> num1(num);
            curr1.push_back(num[i]);
            num1.erase(num1.begin() + i);
            permuteUniqueutil(res, curr1, num1);
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        vector<int> curr;
        
        sort(num.begin(), num.end());
        permuteUniqueutil(res, curr, num);

        return res;
    }
};
