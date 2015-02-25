class Solution {
public:
    int maxArea(vector<int> &height) {
        int low=0;
        int high=height.size()-1;
        int res=0;
        
        while(low<high)
        {
            int curr=min(height[low], height[high])*abs(low-high);
            res=max(res, curr);
            if(height[low]<height[high])
                low++;
            else
                high--;
        }
        
        return res;
    }
};
