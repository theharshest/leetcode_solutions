class Solution {
public:
    int searchutil(int A[], int low, int high, int target)
    {
        if(low>high)
            return -1;
        
        int mid=(high+low)/2;
        if(A[mid]==target)
            return mid;
        else if(A[low]<A[high])
        {
            if(A[mid]<target)
                return searchutil(A, mid+1, high, target);
            else
                return searchutil(A, low, mid-1, target);
        }
        else
        {
            return max(searchutil(A, mid+1, high, target), searchutil(A, low, mid-1, target));
        }
    }

    int search(int A[], int n, int target) {
        return searchutil(A, 0, n-1, target);
    }
};
