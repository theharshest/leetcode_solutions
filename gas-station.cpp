class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n=gas.size();
        int j;
        
        for(int i=0; i<n;)
        {
            int gasleft=0;
            
            for(j=0; ; j++)
            {
                int ind=(i+j)%n;
                gasleft+=gas[ind]-cost[ind];
                
                if(gasleft<0)
                {
                    i+=j+1;
                    break;
                }
                
                if(j==n-1)
                    return i;
            }
        }
        
        return -1;
    }
};
