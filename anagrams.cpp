class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        unordered_map<string, vector<string> > wordmap;
        
        for(int i=0; i<int(strs.size()); i++)
        {
            string tmp=strs[i];
            sort(tmp.begin(), tmp.end());

            wordmap[tmp].push_back(strs[i]);
        }
        
        unordered_map<string, vector<string> >::iterator it=wordmap.begin();
        
        for(; it!=wordmap.end(); it++)
        {
            vector<string> tmp=it->second;
            if(tmp.size()>1)
            {
                for(int i=0; i<int(tmp.size()); i++)
                {
                    res.push_back(tmp[i]);
                }
            }
        }
        
        return res;
    }
};
