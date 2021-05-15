 //find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
 // You cannot break an item, either pick the complete item or don’t pick it (0-1 property).
#include <iostream>
#include <algorithm>
using namespace std;

int knapSack(int wt[],int val[],int W,int n) //T.C = O(2^n)
{
    if(n==0 || W==0) //Base Condition //smallest valid i/p
        return 0;
    if(wt[n-1] <= W) //star from end element
        return max(val[n-1]+knapSack(wt,val,W-wt[n-1],n-1) , knapSack(wt,val,W,n-1)); //Return the maximum of two cases: (1) nth item included (2) not included
    else if(wt[n-1] > W) //this item cannot be included in the optimal solution
        return knapSack(wt,val,W,n-1);
}
int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50; //capacity of knapsack
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(wt,val,W,n);  //Returns the value of maximum profit //220
    return 0;
}
/*
Overlapping Sub-problems property
wt[] = {1, 1, 1}, W = 2, val[] = {10, 20, 30}
                       K(n, W)
                       K(3, 2)
                   /            \
                 /                \
            K(2, 2)                  K(2, 1)
          /       \                  /    \
        /           \              /        \
       K(1, 2)      K(1, 1)        K(1, 1)     K(1, 0)
       /  \         /   \          /   \
     /      \     /       \      /       \
K(0, 2)  K(0, 1)  K(0, 1)  K(0, 0)  K(0, 1)   K(0, 0)
*/
