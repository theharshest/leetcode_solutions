class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n=digits.size();
        int carry=1;
        
        for(int i=n-1; i>=0; i--)
        {
            if(carry==0)
                continue;

            if(digits[i]==9)
            {
                if(i==0 && carry==1)
                {
                    fill(digits.begin(), digits.end(), 0);
                    vector<int> res;
                    res.push_back(1);
                    res.insert(res.end(), digits.begin(), digits.end());
                    return res;
                }
                digits[i]=0;
                carry=1;
            }
            else if(digits[i]!=9)
            {
                digits[i]++;
                carry=0;
            }
        }
        
        return digits;
    }
};
