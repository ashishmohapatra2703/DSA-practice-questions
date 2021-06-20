/*Consider a rat placed at (0, 0) in a square matrix of order N * N. 
It has to reach the destination at (N - 1, N - 1). 
Find all possible paths that the rat can take to reach from source to destination. 
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 

Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it
while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

Input: N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}   (4x4 matrix)
Output:  DDRDRR , DRDDRR  (list of paths in lexicographically sorted order)    */

class Solution{
    public:
    void RatInMaze(int srcRow, int srcCol, 
                    int destRow, int destCol,   
                    vector<vector<int>> &maze, vector<vector<bool>> &visited, 
                    string path, vector<string> &paths)
    {
        if(srcRow<0 || srcRow>destRow || 
           srcCol<0 || srcCol>destCol || 
           maze[srcRow][srcCol] == 0  ||
           visited[srcRow][srcCol] == true)
        {
            return; //no path exists
        }
        if(srcRow==destRow && srcCol==destCol)
        {
            paths.push_back(path);
            return;
        }
        
        visited[srcRow][srcCol] = true;
        RatInMaze(srcRow-1, srcCol, destRow, destCol, maze, visited, path+"U", paths);
        RatInMaze(srcRow+1, srcCol, destRow, destCol, maze, visited, path+"D", paths);
        RatInMaze(srcRow, srcCol-1, destRow, destCol, maze, visited, path+"L", paths);
        RatInMaze(srcRow, srcCol+1, destRow, destCol, maze, visited, path+"R", paths);
        visited[srcRow][srcCol] = false;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        vector<vector<bool>> isVisited(n+1 , vector<bool>(n+1, false));
        vector<string> pathsfromSrcToDest;
        string path = "";
        
        RatInMaze(0, 0, n-1, n-1, m, isVisited, path, pathsfromSrcToDest);
        
        sort(pathsfromSrcToDest.begin(), pathsfromSrcToDest.end());
        return pathsfromSrcToDest;
    }
};