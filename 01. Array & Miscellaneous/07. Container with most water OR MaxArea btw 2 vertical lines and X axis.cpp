/*Naive Approach: The idea is quite simple and involves checking every pair of boundaries or array element and 
find out the maximum area under any pair of boundaries.

Efficient Approach: Given an array of heights of lines of boundaries of the container, 
find the maximum water that can be stored in a container. 
So start with the first and last element and check the amount of water that can be contained and store that container. 
 Now the question arises is there any better boundaries or lines that can contain maximum water. 
 So there is a clever way to find that. Initially, there are two indices the first and last index pointing to the first and the last element
  (which acts as boundaries of the container),
   if the value first index is less than the last index increase the first index else decrease the last index.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int MaxAreaBetweenTwolines(int height[], int n) 
{
    int start = 0;
    int end = n-1;
    
    int maxArea = 0;
    while(start<end)
    {
        int currentArea = min(height[start] , height[end]) * (end-start);
        
        maxArea = max(maxArea, currentArea);
        
        if(height[start] < height[end])
            start++;
        else if(height[start] > height[end])
            end--;
        else if(height[start] == height[end])
            start++; //or end-- either one
    }
    return maxArea;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int height[n];
        for(int i=0; i<n; i++) 
            cin>>height[i];
        
        int MaxWaterContainer = MaxAreaBetweenTwolines(height, n);
        cout<< MaxWaterContainer <<endl;
    }
}