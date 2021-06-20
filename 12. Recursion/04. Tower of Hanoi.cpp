//T.C = (2ⁿ)
#include <iostream>
using namespace std;

//M-1
void TOH(int n,int source,int destin,int helper,int &totalsteps)
{
    totalsteps ++;
    if(n==1)
    {
        cout<<"move disk "<<n<<" from rod "<<source<<" to rod "<<destin<<endl;
        return;                                                      //base condition
    }
    
    TOH(n-1, source, helper, destin, totalsteps);                   //hypothesis 1
    cout<<"move disk "<<n<<" from rod "<<source<<" to rod "<<destin<<endl; //induction
    TOH(n-1, helper, destin, source, totalsteps);                   //hypothesis 2
}

//M-2 (when named disk move is not required)
void TOH(int n,int source,int destin,int helper,int &totalsteps)
{
    if(n==1)
    {
        totalsteps ++;
        cout<<"move disk from rod "<<source<<" to rod "<<destin<<endl;
        return;
    }
    
    TOH(n-1, source, helper, destin, totalsteps); 
    TOH(1, source, destin, helper, totalsteps);   
    TOH(n-1, helper, destin, source, totalsteps);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int source = 1;
        int helper = 2;
        int destin = 3;
        int totalsteps = 0;
        
        TOH(n, source, destin, helper, totalsteps);
        cout<< totalsteps <<endl; // or directly totalsteps = pow(2,N) - 1;
    }
}
/*Input:
    2
    2
    3
Output:
move disk 1 from rod 1 to rod 2
move disk 2 from rod 1 to rod 3
move disk 1 from rod 2 to rod 3
3
move disk 1 from rod 1 to rod 3
move disk 2 from rod 1 to rod 2
move disk 1 from rod 3 to rod 2
move disk 3 from rod 1 to rod 3
move disk 1 from rod 2 to rod 1
move disk 2 from rod 2 to rod 3
move disk 1 from rod 1 to rod 3
7                               */
