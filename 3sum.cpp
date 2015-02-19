class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        
        if(num.size()<3)
            return res;
        
        for(int i=0; i<num.size(); i++)
        {
            if(i>0 && num[i]==num[i-1])
                continue;
                
            int target=-1*num[i];
            
            int low=i+1;
            int high=num.size()-1;
            
            while(low<high)
            {
                if(low>i+1 && num[low]==num[low-1])
                {
                    low++;
                    continue;
                }
                
                if(high<int(num.size())-1 && num[high]==num[high+1])
                {
                    high--;
                    continue;
                }
                
                int currsum=num[low]+num[high];
                
                if(currsum<target)
                    low++;
                else if(currsum>target)
                    high--;
                else
                {
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[low]);
                    tmp.push_back(num[high]);
                    res.push_back(tmp);
                    low++;
                    high--;
                }
            }
        }
        
        return res;
    }
};
