/* Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and
 find the BFS traversal of the graph starting from the 0th vertex, 
 from left to right according to the graph. 
 Also, you should only take nodes directly or indirectly connected from Node 0 in consideration. */

class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> bfs;
	    vector<bool> visited(V, false); //to mark all the vertices as not visited
	    queue<int> q;
	    
	    q.push(0);   //pushing first vertex in queue.
	    visited[0] = true; //mark first vertex as visited(true).
	    
	    while(! q.empty())
	    {
	        int node = q.front();
	        q.pop();            //popping the front element from queue
	        bfs.push_back(node); //adding it in output list
	        
	        for(auto near : adj[node]) //traversing over all the neighbours of front element.
	        {
	            if(! visited[near])
	            {
	                q.push(near);
	                visited[near] = true; //if they aren't visited, add to queue and mark them visited
	            }
	        }
	    }
	    return bfs;
	}
};

/*  for(int i=0; i<V; i++)  if there are >1 components of graph
	{
		if(! visited[i])
		{
			BFS......
		}
	} */
