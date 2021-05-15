#include <iostream>
#include <vector>
using namespace std;

vector<string> ways;

void pathToReachNthStair(string op,int N, int steps[]) //ip => N
{
    if(N < 0)
        return;
    if(N == 0)
    {
        ways.push_back(op);
        return;
    }
    
    string op1 = op + to_string(steps[0]);
    string op2 = op + to_string(steps[1]);
    string op3 = op + to_string(steps[2]);
        
    pathToReachNthStair(op1, N-steps[0], steps);
    pathToReachNthStair(op2, N-steps[1], steps);
    pathToReachNthStair(op3, N-steps[2], steps);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n=3; //size of steps[] array
        int steps[n]; //steps[] array with (sorted) only 1, 2, 3 allowed steps
        steps[0] = 1;
        steps[1] = 2;
        steps[2] = 3;

        int N;
        cin>>N; //Top ~ Total No. of Steps

        string op = "";
        pathToReachNthStair(op, N, steps); 
        
        for(string x: ways) //With Different Arrangement/Order of each Subset
            cout<<x<<" , ";
        cout<<endl;
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