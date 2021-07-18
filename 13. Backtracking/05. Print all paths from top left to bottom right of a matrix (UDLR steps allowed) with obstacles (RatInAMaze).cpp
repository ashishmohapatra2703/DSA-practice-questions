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

//M-1
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
        RatInMaze(srcRow+1, srcCol, destRow, destCol, maze, visited, path+"D", paths);
        RatInMaze(srcRow, srcCol-1, destRow, destCol, maze, visited, path+"L", paths);
        RatInMaze(srcRow, srcCol+1, destRow, destCol, maze, visited, path+"R", paths);
        RatInMaze(srcRow-1, srcCol, destRow, destCol, maze, visited, path+"U", paths);
        visited[srcRow][srcCol] = false;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        vector<vector<bool>> isVisited(n+1 , vector<bool>(n+1, false));
        vector<string> pathsfromSrcToDest;
        string path = "";
        
        RatInMaze(0, 0, n-1, n-1, m, isVisited, path, pathsfromSrcToDest);
        return pathsfromSrcToDest;
    }
};


//M-2 {another syle of code}
class Solution{
private: 
    int rowMove[4] = {1,0,0,-1};
    int colMove[4] = {0,-1,1,0};
    char direction[4] = {'D','L','R','U'};
    
    bool isSafeToMove(int newRow, int newCol, int &destRow, int &destCol, vector<vector<int>> &maze)
    {
        if(newRow<0 || newRow>destRow || newCol<0 || newCol>destCol || maze[newRow][newCol] == 0)
            return false; //no path exists
            
        return true; //if all above checks are false
        //i.e, if(newRow>=0 && newCol>=0 && newRow<=n-1 && j<=n-1 && maze[newRow][newCol]==1)  => safe to move
    }
public:
    void RatInMaze(int &srcRow, int &srcCol, 
                    int &destRow, int &destCol,   
                    vector<vector<int>> &maze,
                    string &path, vector<string> &paths)
    {
        if(srcRow==destRow && srcCol==destCol)
        {
            paths.push_back(path);
            return;
        }
        
        for(int i=0; i<4; i++)
        {
            if(isSafeToMove(srcRow+rowMove[i], srcCol+colMove[i], destRow, destCol, maze) == true)
            {
                maze[srcRow][srcCol] = 0; //mark the current cell of the maze as visited 
                path.push_back(direction[i]);
                srcRow += rowMove[i];
                srcCol += colMove[i];
                RatInMaze(srcRow, srcCol, destRow, destCol, maze, path, paths);
                srcRow -= rowMove[i];
                srcCol -= colMove[i];
                path.pop_back();
                maze[srcRow][srcCol] = 1; //remove the visited mark from the current cell
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        if(m[0][0]==0 || m[n-1][n-1]==0)
            return {};
            
        vector<string> pathsfromSrcToDest;
        string path = "";
        int srcR = 0;
        int srcC = 0;
        int targetR = n-1;
        int targetC = n-1;
        
        RatInMaze(srcR, srcC, targetR, targetC, m, path, pathsfromSrcToDest);
        return pathsfromSrcToDest;
    }
};