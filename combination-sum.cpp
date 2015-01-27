class Solution {
public:
    bool combinationSumutil(vector<vector<int> > &res, vector<int> curr, int currsum, vector<int> &candidates, int target, int ind)
    {
    	// If sum for the current sequence equals target
        if(currsum==target)
        {
        	sort(curr.begin(), curr.end());
            res.push_back(curr);
            //return true;
        }
        
        // Look for each element in candidate set, each time from start
        for(int i=ind; i<int(candidates.size()); i++)
        {
            if(currsum+candidates[i]<=target)
            {
                curr.push_back(candidates[i]);
                
                // If current+1 call succeeds, then the current decision is right
                if(combinationSumutil(res, curr, currsum+candidates[i], candidates, target, i))
                    return true;
                
                // Undo current decision, if current+1 call fails
                curr.pop_back();
            }
        }
        
        // Backtrack if current call fails
        return false;
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;

        vector<int> curr;

        combinationSumutil(res, curr, 0, candidates, target, 0);

        return res;
    }
};
