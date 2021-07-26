/* Given an undirected graph with V vertices and E edges, 
check whether it contains any cycle or not. 
It may have disconnected components */

class Solution {
public:
    bool isCyclePresent(int currNode, int parent, bool visited[], vector<int> adj[])
    {
        visited[currNode] = true;
        
        for(auto near: adj[currNode])
        {
            if(! visited[near])
            {
                if(isCyclePresent(near, currNode, visited, adj))  
                    return true;
            }
            else if(visited[near])
            {
                if(near != parent)
                    return true;
            }
        }
        return false;
    }
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
        bool visited[V];
        memset(visited, false, sizeof(visited));
	    
	    for(int i=0; i<V; i++)
	    {
	        if(! visited[i])
	        {
	            if(isCyclePresent(i, -1, visited, adj)) 
	                return true;
	        }
	    }
	    return false;
	}
};