class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int low=0;
        int high=n-1;
        
        while(high-low>=3)
        {
            int mid=(low+high)/2;
            if(A[mid]==target)
            {
                if(A[mid]>=target)
                    return mid;
                else
                    return mid+1;
            }
            else if(A[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        
        for(int i=low; i<=high; i++)
            if(target<=A[i])
                return i;
                
        return high+1;
    }
};
