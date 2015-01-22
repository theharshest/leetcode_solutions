class Solution {
public:
    int numTrees(int n) {
        vector<int> trees{1, 1, 2};
        
        if(n<=2)
            return trees[n];
            
        for(int i=3; i<=n; i++)
        {
            int curr=0;
            for(int j=1; j<=i; j++)
            {
                curr+=trees[j-1]*trees[i-j];
            }
            trees.push_back(curr);
        }
        
        return trees[int(trees.size())-1];
    }
};
