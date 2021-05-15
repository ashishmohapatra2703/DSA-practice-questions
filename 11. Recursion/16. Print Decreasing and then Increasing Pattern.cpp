/*Print a sequence of numbers starting with N, without using loop, 
in which  A[i+1] = A[i] - 5,  if  A[i]>0, else A[i+1]=A[i] + 5  repeat it until A[i]=N. 
Input:
    2
    16
    10
Output:
    16 11 6 1 -4 1 6 11 16
    10 5 0 5 10         */
#include <iostream>
using namespace std;

void IncPattern(int N , int Orig) 
{
    cout<< N <<" ";
    
    if(N == Orig)
        return;
    
    IncPattern(N+5 , Orig);
}

void DecPattern(int N , int Orig) 
{
    if(N <= 0)
    { 
        IncPattern(N , Orig);
        return;
    }
    
    cout<< N <<" ";
    
    DecPattern(N-5 , Orig);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        
        DecPattern(N , N);
        cout<<endl;
    }
}