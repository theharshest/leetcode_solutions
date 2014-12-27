class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> hash;
        vector<int> res;
        
        for(int i=0; i<int(numbers.size()); i++)
            hash[numbers[i]]=i+1;
            
        for(int i=0; i<int(numbers.size()); i++)
        {
            if(hash.find(target-numbers[i])!=hash.end() && hash[target-numbers[i]]!=i+1)
            {
                res.push_back(i+1);
                res.push_back(hash[target-numbers[i]]);
                sort(res.begin(), res.end());
                return res;
            }
        }
    }
};
