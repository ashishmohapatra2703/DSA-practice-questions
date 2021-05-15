#include <iostream>
#include <cstring>
using namespace std;

int dp[1001][1001][2][3]; //Constraints: 1<= N <=1000

int ConstraintsKnapsackWithPermutation(int N,int acount,int bcount,int ccount)
{
    if( (acount<0 || bcount<0 || ccount<0) && N>=0 )
        return 0;
    if(N == 0) //with any of the string count present
        return 1; //{} 1 choice to select none of them 
    if(bcount == 0 && ccount == 0)
        return 1; //only 1 string can be formed i.e, aaaaa.. of N length
    
    if(dp[N][acount][bcount][ccount] != -1)
        return dp[N][acount][bcount][ccount];
        
    return dp[N][acount][bcount][ccount] = 
            ConstraintsKnapsackWithPermutation(N-1,acount-1,bcount,ccount)+
            ConstraintsKnapsackWithPermutation(N-1,acount,bcount-1,ccount)+
            ConstraintsKnapsackWithPermutation(N-1,acount,bcount,ccount-1);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp, -1 ,sizeof(dp));
        int N;
        cin>>N;
        
        int acount = 1000;
        int bcount = 1;
        int ccount = 2;
        
        int NoOfStringoflenN = ConstraintsKnapsackWithPermutation(N,acount,bcount,ccount); 
        cout<< NoOfStringoflenN <<endl; 
    }
}
