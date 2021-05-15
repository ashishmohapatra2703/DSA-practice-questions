//Refr. : Find subseq. (triplet only) whose sum = target sum in a sorted array
#include <iostream>
#include <algorithm>
using namespace std;

bool isPythagorasTripletPresent(int A[], int n) 
{
    sort(A , A+n , greater<int>()); //reverse sort the array
    
    for(int i=0; i<n; i++)
    {
        A[i] = A[i]*A[i]; //each term squared
    }
    
    for(int i=0; i<n-2; i++)
    {
        int sumof2terms = A[i];
        
        int start = i+1;
        int end = n-1;
        while(start < end)
        {
            if(A[start] + A[end] == sumof2terms)
                return true;
            else if(A[start] + A[end] < sumof2terms)
                end--;
            else if(A[start] + A[end] > sumof2terms)
                start++;
        }
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        for(int i=0; i<n; i++) 
            cin>>A[i];
            
        bool ans = isPythagorasTripletPresent(A, n);
        if(ans)
            cout<< "Yes" <<endl;
        else
            cout<< "No" <<endl;
    }
}