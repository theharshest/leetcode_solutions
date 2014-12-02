class Solution {
public:
    int getmin(vector<int> &num, int x, int y) {
        if(x==y)
            return num[x];
        else if(y-x==1)
            return min(num[x], num[y]);
        else
        {
            int mid=(x+y)/2;
            if(num[mid]<num[mid+1] && num[mid]<num[mid-1])
                return num[mid];
            
            return min(getmin(num, mid+1, y), getmin(num, x, mid-1));
        }
    }

    int findMin(vector<int> &num) {
        int n=num.size()-1;
        
        return getmin(num, 0, n);
    }
};
