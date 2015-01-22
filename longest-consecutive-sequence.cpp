class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> visited;
        int res=0;
        
        for(int i=0; i<int(num.size()); i++)
            visited[num[i]]=false;
            
        for(int i=0; i<int(num.size()); i++)
        {
            int curr=1;
            
            if(visited[num[i]]==true)
                continue;
            
            visited[num[i]]=true;
            
            int less=num[i]-1, more=num[i]+1;
            
            while(visited.find(less)!=visited.end())
            {
                visited[less]=true;
                less--;
                curr++;
            }
            
            while(visited.find(more)!=visited.end())
            {
                visited[more]=true;
                more++;
                curr++;
            }
            
            res=max(res, curr);
        }
        
        return res;
    }
};
