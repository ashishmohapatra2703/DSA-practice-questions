/*Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach to find the DFS traversal of the graph 
starting from the 0th vertex from left to right according to the graph..*/

class Solution {
public:
    void DFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &dfs)
    {
        dfs.push_back(node);
        visited[node] = true;
        
        for(auto near: adj[node])
        {
            if(! visited[near])
                DFS(near, adj, visited, dfs); 
        }
    }
	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> dfs;
	    vector<bool> visited(V, false);
	    
	    for(int i=0; i<V; i++)
	        if(!visited[i])
	            DFS(i, adj, visited, dfs);
	    
	    return dfs;
	}
};



//The algorithm is, we visit the source node and recursively call its neighbours which are not visited.