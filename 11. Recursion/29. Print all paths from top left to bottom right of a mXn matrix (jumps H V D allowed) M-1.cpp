/*print all the possible paths from top left to bottom right of a mXn matrix 
from each cell, in a single move you are allowed to 
   jump 1 or more steps horizontally (as h1, h2, .. ), 
or jump 1 or more steps vertically (as v1, v2, ..) 
or jump 1 or more steps diagonally (as d1, d2, ..).  

i/p: 2x2
o/p: H1V1, V1H1, D1 
i/p: 3x2
o/p: H1V1V1, H1V2, V1H1V1, V1V1H1, V1D1, V2H1, D1V1 */
 
#include <iostream>
#include <vector>
using namespace std;

vector<string> pathsfromTLtoBR(int srcRow, int srcCol, int destRow, int destCol)
{
    if(srcRow == destRow && srcCol == destCol)
        return {""};
        
    vector<string> fullPathsToDest;
    
    for(int move=1; move<=destCol-srcCol ; move++)
    {
        vector<string> pathsafterMoveHoriz = pathsfromTLtoBR(srcRow, srcCol+move, destRow, destCol);
        for(string x: pathsafterMoveHoriz)
            fullPathsToDest.push_back("H" + to_string(move) + x);
    }
    for(int move=1; move<=destRow-srcRow ; move++)
    {
        vector<string> pathsafterMoveVert = pathsfromTLtoBR(srcRow+move, srcCol, destRow, destCol);
        for(string x: pathsafterMoveVert)
            fullPathsToDest.push_back("V" + to_string(move) + x);
    }
    for(int move=1; move<=destCol-srcCol && move<=destRow-srcRow ; move++)
    {
        vector<string> pathsafterMoveDiag = pathsfromTLtoBR(srcRow+move, srcCol+move, destRow, destCol);
        for(string x: pathsafterMoveDiag)
            fullPathsToDest.push_back("D" + to_string(move) + x);
    }
    
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