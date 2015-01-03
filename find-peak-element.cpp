class Solution {
public:
    int findPeakElementutil(const vector<int> &num, int low, int high)
    {
        if(low==high)
            return low;
        else if(low+1==high)
        {
            if(num[low]<num[high])
                return high;
            else
                return low;
        }
        
        int mid=(low+high)/2;
        if(num[mid]>num[mid+1] && num[mid]>num[mid-1])
            return mid;
        if(num[mid-1]>=num[mid])
            return findPeakElementutil(num, low, mid-1);
        else if(num[mid+1]>=num[mid])
            return findPeakElementutil(num, mid+1, high);
        else
            return findPeakElementutil(num, mid+1, high);
    }

    int findPeakElement(const vector<int> &num) {
        int n=num.size()-1;
        return findPeakElementutil(num, 0, n);
    }
};
