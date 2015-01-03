class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n=num.size();
        int pivot=-1;
        
        for(int i=n-1; i>0; i--)
        {
            if(num[i]>num[i-1])
            {
                pivot=i-1;
                break;
            }
        }
        
        if(pivot==-1)
            sort(num.begin(), num.end());
        else
        {
            int diff=num[pivot+1]-num[pivot];
            int pivot2=pivot+1;
            for(int i=pivot+2; i<n; i++)
            {
                int newdiff=num[i]-num[pivot];
                if(newdiff>0 && newdiff<diff)
                {
                    diff=newdiff;
                    pivot2=i;
                }
            }
            swap(num[pivot], num[pivot2]);
            sort(num.begin()+pivot+1, num.end());
        }
    }
};
