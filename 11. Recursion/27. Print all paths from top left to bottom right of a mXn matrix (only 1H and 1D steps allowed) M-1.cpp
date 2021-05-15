//print all the possible paths from top left to bottom right of a mXn matrix 
//with the constraints that from each cell you can either move only to right or down.
// i/p : 3x3
// o/p : RRDD, RDRD, RDDR, DRRD, DRDR, DDRR

#include <iostream>
#include <vector>
using namespace std;

vector<string> pathsfromTLtoBR(int srcRow, int srcCol, int destRow, int destCol)
{
    if(srcRow == destRow && srcCol == destCol)
        return {""};
        
    vector<string> pathsafter1RightStep;
    vector<string> pathsafter1DownStep;
    
    if(srcCol < destCol)
        pathsafter1RightStep = pathsfromTLtoBR(srcRow, srcCol+1, destRow, destCol);
    if(srcRow < destRow)
        pathsafter1DownStep = pathsfromTLtoBR(srcRow+1, srcCol, destRow, destCol);
        
    vector<string> fullPathsToDest;
    
    for(string x: pathsafter1RightStep)
        fullPathsToDest.push_back("R" + x);
    for(string x: pathsafter1DownStep)
        fullPathsToDest.push_back("D" + x);
    
    return fullPathsToDest;
}

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int m; cin>>m;
        int n; cin>>n;
        
        vector<string> ways = pathsfromTLtoBR(1, 1, m, n);
        
        for(int i=0; i<ways.size(); i++)
        {
            cout << ways[i];
            if(i < ways.size()-1) 
                cout << ", ";
        }
        cout<<endl;
    }
}