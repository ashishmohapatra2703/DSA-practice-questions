// M-1  [Simple Linear Search]
/* In this method, the total number of comparisons is 1 + 2(n-2) in the worst case 
and 1 + (n–2) in the best case.   In the above implementation, 
the worst case occurs when elements are sorted in descending order and 
the best case occurs when elements are sorted in ascending order. */
#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    pair<int,int> mima;
    
    if(n==1)
    {
        mima.first = arr[0];
        mima.second = arr[0];
    }
    else
    {
        if(arr[0]<arr[1])
        {
            mima.first = arr[0];
            mima.second = arr[1];
        }
        else
        {
            mima.first = arr[1];
            mima.second = arr[0];
        }

        for(int i=2; i<n; i++)
        {
            if(arr[i] < mima.first)
                mima.first = arr[i];
            else if(arr[i] > mima.second)
                mima.second = arr[i];
        }
    }
    
    cout<<"min element = "<<mima.first<<endl;
    cout<<"max element = "<<mima.second<<endl;
}

//M-2    [Compare in Pairs]
/* If n is odd then initialize min and max as first element. 
If n is even then initialize min and max as minimum and maximum of the first two elements respectively. 
For rest of the elements, pick them in pairs and compare their 
maximum and minimum with max and min respectively.  
	Time Complexity: O(n)
Total number of comparisons: 
If n is odd:  3*(n-1)/2  
If n is even: 1 Initial comparison for initializing min&max and 3(n-2)/2 comparisons for rest of the elements  
            =  1 + 3*(n-2)/2 = 3n/2 -2              
            it is n-2 because first two elements is already checked before going to while loop 
            and updated i=2 there. */
#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++)
        cin>>A[i];
    
    pair<int,int> mima;
    
    int i=0;
    if(n%2 == 0) //even 
    {
        if(A[0] < A[1])
        {
            mima.first = A[0];
            mima.second = A[1];
        }
        else
        {
            mima.first = A[1];
            mima.second = A[0];
        }
        i = 2;
    }
    else //odd
    {
        mima.first = A[0];
        mima.second = A[0];
        i = 1;
    }
    
    
    for(i; i<=n-2; i+=2) //increment +2 as checking pair wise, until 2nd last element  
    {
        if(A[i] < A[i+1])
        {
            if(A[i] < mima.first)
                mima.first = A[i];
            if(A[i+1] > mima.second)
                mima.second = A[i+1];
        }
        else
        {
            if(A[i] > mima.second)
                mima.second = A[i];
            if(A[i+1] < mima.first)
                mima.first = A[i+1];
        }
    }

    cout<<"min element = "<<mima.first<<endl;
    cout<<"max element = "<<mima.second<<endl;
}









