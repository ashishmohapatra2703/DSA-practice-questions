#include <iostream>
using namespace std;

void printnumber(int n) 
{
    if(n==0)
        return;
    
    //cout<<n<<" ";  //for printing n to 1 (calling phase)
    printnumber(n-1); 
    cout<<n<<" ";    //for printing 1 to n (returning phase)
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n; cin>>n;
        printnumber(n);
        cout<<endl;
    }
}


// i/p: 7
// o/p: 7 6 5 4 3 2 1 1 2 3 4 5 6 7 
#include <iostream>
using namespace std;

void printDecreasingIncreasing(int n) 
{
    if(n==0)
        return;
    
    cout<< n <<" ";  
    printDecreasingIncreasing(n-1); 
    cout<< n <<" ";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n; cin>>n;
        printDecreasingIncreasing(n);
        cout<<endl;
    }
}