#include <iostream>
#include <vector>
using namespace std;

vector<string> pathToReachNthStair(int steps[], int N)
{
    if(N == 0)
        return {""};  // phi -> 1 way
    if(N < 0)
        return {};
        
    vector<string> pathAfter1step = pathToReachNthStair(steps, N-steps[0]);
    vector<string> pathAfter2step = pathToReachNthStair(steps, N-steps[1]);
    vector<string> pathAfter3step = pathToReachNthStair(steps, N-steps[2]);
    vector<string> fullPathToNthStair;
    
    for(string x: pathAfter1step)
        fullPathToNthStair.push_back( to_string(steps[0]) + x );
    for(string x: pathAfter2step)
        fullPathToNthStair.push_back( to_string(steps[1]) + x );
    for(string x: pathAfter3step)
        fullPathToNthStair.push_back( to_string(steps[2]) + x );
        
    return fullPathToNthStair;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n=3; //size of steps[] array
        int steps[3]; //steps[] array with (sorted) only 1, 2, 3 allowed steps
        steps[0] = 1;
        steps[1] = 2;
        steps[2] = 3;

        int N;
        cin>>N; //Top ~ Total No. of Steps

        vector<string> ways = pathToReachNthStair(steps, N); 
        //With Different Arrangement/Order of each Subset
        for(string x: ways)
            cout<<x<<" , ";
    }
}
/* i/p: N = 4
   o/p: 1111
        112
        121
        13
        211
        22
        31 */