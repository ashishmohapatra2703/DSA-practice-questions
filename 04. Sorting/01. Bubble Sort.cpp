#include <iostream>
#include <stdio.h>
using namespace std;

template <class T>
void Print(T &vec, int n, string s)
{
    cout<<s<<": ["<<flush;
    for (int i=0; i<n; i++)
    {
        cout<< vec[i] <<flush;
        if (i < n-1)
            cout<<", "<<flush;
    }
    cout<< "]" <<endl;
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp; //dereferencing of pointer
}

void BubbleSort(int A[], int n)
{
    int flag = 0;
    for (int i=0; i<n-1; i++) //(n-1) passes
    {
        for (int j=0; j<n-1-i; j++) //in every successive pass, 1 comparison is reduced
        {
            if (A[j] > A[j+1])
            {
                swap(&A[j], &A[j+1]); //pass by address
                flag = 1;
            }
        }
        if (flag == 0)
            return;
    }
}

int main()
{

    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A)/sizeof(A[0]);
    Print(A, n, " Given A");

    BubbleSort(A, n); //it is adaptive and stable algo.
    Print(A, n, " Sorted A");

    return 0;
}
