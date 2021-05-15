//find the maximum no. of segments we can make by cutting only of the sizes given
//Given an integer N denoting the Length of a line segment. you need to cut the line segment in such a way that the
// cut length of a line segment each time is integer either x , y or z. 
// and after performing all cutting operation the total number of cutted segments must be maximum.

//Example:
// (1) N = 4
//    x=2 y=1 z=1
// o/p = 4 ;total length is 4 & cut lengths are 2,1,1. We can make maximum 4 segments each of length 1
// (2) N = 7
//    x=5 y=2 z=2
//o/p = 2; We can make maximum 2 segments of length 5 and 2

#include <iostream>
#include <climits>
using namespace std;

int MaxMemberUnboundedSubset(int piece[], int N)
{
    int dp[4][N+1];
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<N+1; j++)
        {
            if(j==0)
                dp[i][j] = 0;
            if(i==0)              //Base Condition initialization
                dp[i][j] = INT_MIN;
        }
    }
    for (int i=1,j=1; j<N+1; j++) //2nd row initialization
    {
        if(j%piece[0] == 0)    //here piece[i-1] ~ piece[0]
            dp[i][j] = j/piece[0];
        else
            dp[i][j] = INT_MIN;
    }

    for (int i=2; i<4; i++)
    {
        for (int j=1; j<N+1; j++)
        {
            if(piece[i-1] <= j)
                dp[i][j] =  max( 1+dp[i][j-piece[i-1]] , dp[i-1][j] ) ; //including the segment will raise the number of segments by 1
            else if(piece[i-1] > j)
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[3][N];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N; //rod length

        int n=3; //here size of array = 3 (Constrains in piece_length)
        int piece[3]; //array of pieces(size)
        for (int i=0; i<3; i++)
        {
            cin>>piece[i];
        }

        int ans = MaxMemberUnboundedSubset(piece, N);
        cout<< ans <<endl;
    }
}
// Can be multiple occurrence of the same item
//The imp. point here is,the pieces choosen should add up to the N length intitially given

//VERY SIMILAR TO ***Coin Change Problem Minimum Numbers of coins***
// change here is MinMemberUnboundedSubset to MaxMemberUnboundedSubset
