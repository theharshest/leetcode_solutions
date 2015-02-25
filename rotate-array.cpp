class Solution {
public:
    void rotateutil(int nums[], int low, int high)
    {
        while(low<high)
        {
            swap(nums[low], nums[high]);
            low++;
            high--;
        }
    }

    void rotate(int nums[], int n, int k) {
        k=k%n;
        int ind=n-k;
     
        rotateutil(nums, 0, ind-1);
        rotateutil(nums, ind, n-1);
        rotateutil(nums, 0, n-1);
    }
};
