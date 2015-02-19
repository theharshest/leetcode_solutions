/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
            return node;
        
        queue<UndirectedGraphNode *> q1;
        unordered_map<int, UndirectedGraphNode *> visited;
        q1.push(node);
        
        UndirectedGraphNode *start=new UndirectedGraphNode(node->label);
        visited[node->label]=start;
        
        while(!q1.empty())
        {
            UndirectedGraphNode *oldnode=q1.front();
            q1.pop();
            int val=oldnode->label;
            UndirectedGraphNode *newnode=visited[val];
            
            for(int i=0; i<(oldnode->neighbors).size(); i++)
            {
                if(visited.find((oldnode->neighbors)[i]->label) == visited.end())
                {
                    UndirectedGraphNode *tmp=new UndirectedGraphNode((oldnode->neighbors)[i]->label);
                    (newnode->neighbors).push_back(tmp);
                    q1.push((oldnode->neighbors)[i]);
                    visited[tmp->label]=tmp;
                }
                else
                    (newnode->neighbors).push_back(visited[(oldnode->neighbors)[i]->label]);
            }
        }
        
        return start;
    }
};
