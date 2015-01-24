class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        
        for(int i=1; i<n; i++)
        {
            string newres="";
            
            for(int j=0; j<int(res.length()); j++)
            {
                int count=1;
                char dig=res[j];
                while(j+1<int(res.length()) && res[j+1]==dig)
                {
                    count++;
                    j++;
                }
                newres+=to_string(count)+dig;
            }

            res=newres;
        }
        return res;
    }
};
