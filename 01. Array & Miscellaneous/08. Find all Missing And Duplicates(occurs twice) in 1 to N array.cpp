/*Given an unsorted array of size N of positive integers. 
One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. 
Find these two numbers.
Note: If you find multiple answers then print the Smallest number found. 
      Also, expected solution is O(n) time and constant extra space.*/

//Swap Sort Algo.
//T.C = O(n)
//S.C = O(1)

#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void FindDuplicateAndMissingin1toNarray(int arr[], int N)
{
    int i=0;
    while(i<N)
    {
        if(arr[i] != arr[arr[i]-1])
        {
            swap(arr[i] , arr[arr[i]-1]);
        }
        else if((arr[i] == arr[arr[i]-1]) || (arr[i] == i+1))
        {
            i++;
        }
    }
    for(int i=0; i<N; i++)
    {
        if(arr[i] != i+1)
        {
            cout<<arr[i]<<" "<<i+1;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++) 
            cin>>arr[i];
            
        FindDuplicateAndMissingin1toNarray(arr, n);
        cout<<endl;
    }
}

/*
Example:
Input:
2
2
2 2
3 
1 3 3

Output:
2 1
3 2

Explanation:
Testcase 1: Repeating number is 2 and smallest positive missing number is 1.
Testcase 2: Repeating number is 3 and smallest positive missing number is 2.
*/