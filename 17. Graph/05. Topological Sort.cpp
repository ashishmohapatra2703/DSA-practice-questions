/*Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices 
such that for every directed edge u -> v, vertex u comes before v in the ordering. 
Topological Sorting for a graph is not possible if the graph is not a DAG.*/

class Solution{
public:
    void topoloDFS(int currNode, vector<int> adj[], vector<bool> &visited, stack<int> &topoloSort)
    {
        visited[currNode] = true;
        
        for(auto near: adj[currNode])
        {
            if(! visited[near])
                topoloDFS(near, adj, visited, topoloSort); 
        }
        
        topoloSort.push(currNode);
    }
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> visited(V, false);
	    stack<int> topoloSort;
	    
	    for(int i=0; i<V; i++)
	        if(! visited[i])
	            topoloDFS(i, adj, visited, topoloSort);
	   
	   
	    vector<int> topoloSortVec;
	    while(! topoloSort.empty())
	    {
	        topoloSortVec.push_back(topoloSort.top());
	        topoloSort.pop();
	    }
	    return topoloSortVec;
	}
};

/*In topological sorting, we use a temporary stack. We don’t print the vertex immediately, 
we first recursively call topological sorting for all its adjacent vertices, then push it to a stack.
 Finally, print contents of the stack. 

 Note that a vertex is pushed to stack only when all of its adjacent vertices
  (and their adjacent vertices and so on) are already in the stack. */