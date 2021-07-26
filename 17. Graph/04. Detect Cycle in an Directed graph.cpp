/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, 
check whether it contains any cycle or not. */

//M-1
class Solution{
public:
    //ancestors -> stores all ancestor nodes of currNode
    bool isCyclePresent(int currNode, vector<int> &ancestors, vector<bool> &visited, vector<int> adj[])
    {
        visited[currNode] = true;
        ancestors.push_back(currNode); 
        
        for(auto near: adj[currNode])
        {
            if(! visited[near])
            {
                if(isCyclePresent(near, ancestors, visited, adj)) 
                    return true;
            }
            else if(visited[near])
            {   
                for(auto ancestor: ancestors)
                    if(near == ancestor) //back-edge
                        return true;
            }
        }
        ancestors.pop_back();
        return false;
    }
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<bool> visited(V, false);
	   	vector<int> ancestors;
	   	
	   	for(int i=0; i<V; i++)
	    {
	        if(! visited[i])
	        {
	            if(isCyclePresent(i, ancestors, visited, adj)) 
	                return true;
	        }
	    }
	    return false;
	}
};

//M-2 time OPTIMISED way for checking ancestors
class Solution{
public:
    //ancestor[] -> gives the status of all the ancestors nodes at a currNode state
    bool isCyclePresent(int currNode, vector<bool> &ancestor, vector<bool> &visited, vector<int> adj[])
    {
        visited[currNode] = true;
        ancestor[currNode] = true; 
        
        for(auto near: adj[currNode])
        {
            if(! visited[near])
            {
                if(isCyclePresent(near, ancestor, visited, adj)) 
                    return true;
            }
            else if(visited[near])
            {   
                if(ancestor[near] == true) //back-edge
                    return true;
            }
        }
        ancestor[currNode] = false; 
        return false;
    }
    //Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) 
    {
        vector<bool> visited(V, false);
        vector<bool> ancestor(V, false);
        
        for(int i=0; i<V; i++)
        {
            if(! visited[i])
            {
                if(isCyclePresent(i, ancestor, visited, adj)) 
                    return true;
            }
        }
        return false;
    }
};