// https://practice.geeksforgeeks.org/problems/ncr/0/
#include <iostream>
#include <cstring>
using namespace std;
#define mod 1000000007;

long long F[1001][801];

long long nCr(long long n, long long r) 
{
    if(F[n][r] != -1)
        return F[n][r]; //Memoization
    
    if(r>n)
        return F[n][r]=0; //base condition    
    if(r==0 || r==n)
        return F[n][r]=1; //base condition
    
    return F[n][r] = (nCr(n-1,r-1) + nCr(n-1,r))%mod;
}
int main()
{
    memset(F, -1, sizeof(F));
    long long t;
    cin>>t;
    while(t--)
    {
        long long n; 
        cin>>n;
        long long r;
        cin>>r;
        long long ans = nCr(n, r);
        cout<< ans <<endl;
    }
}