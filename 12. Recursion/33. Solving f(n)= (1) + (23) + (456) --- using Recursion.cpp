/*Input: 1 Output: (1) 																			= 1
  Input: 2 Output: (1) + (2*3) 																	= 7
  Input: 3 Output: (1) + (2*3) + (4*5*6) 														= 127
  Input: 4 Output: (1) + (2*3) + (4*5*6) + (7*8*9*10) 											= 5167
  Input: 5 Output: (1) + (2*3) + (4*5*6) + (7*8*9*10) + (11*12*13*14*15) 						= 365527
  Input: 6 Output: (1) + (2*3) + (4*5*6) + (7*8*9*10) + (11*12*13*14*15) + (16*17*18*19*20*21)  = 39435607 
  Constraints: 1 <= N <= 10   */

// M-1









// M-2 using loops
#include <iostream>
#include <cstring>
using namespace std;

long seq[11];
void nthTermofSequence() 
{
    int k = 1;
    for(int i=1; i<=10; i++)
    {
        for(int j=1; j<=i; j++,k++)
        {
            seq[i] = seq[i] * k;
        }
        seq[i] = seq[i] + seq[i-1];
    }
}
int main()
{
    for(int i=1; i<=10; i++)
        seq[i] = 1;
    nthTermofSequence();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>> n;

	//seq[11] = 0 1 7 127 5167 365527 39435607 6006997207 1226103906007 322796982334807 106460296033918807  
        cout<<seq[n]<<endl;
    }
}