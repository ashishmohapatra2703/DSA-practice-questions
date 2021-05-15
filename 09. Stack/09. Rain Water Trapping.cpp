#include <iostream>
#include <algorithm>
using namespace std;

long RainWaterTrapping(long height[], int n) 
{
    long MaxHeightInLeft[n];
    MaxHeightInLeft[0] = height[0];
    for(int i=1; i<n; i++) 
    {
        MaxHeightInLeft[i] = max(MaxHeightInLeft[i-1],height[i]);
    }
    
    long MaxHeightInRight[n];
    MaxHeightInRight[n-1] = height[n-1];
    for(int i=n-2; i>=0; i--) 
    {
        MaxHeightInRight[i] = max(MaxHeightInRight[i+1],height[i]);
    }
    
    long WaterLevelonEach[n];
    for(int i=0; i<n; i++)
    {
        WaterLevelonEach[i] = min(MaxHeightInLeft[i],MaxHeightInRight[i]) - height[i];
    }
    
    long TotalUnitsofWater = 0;
    for(int i=0; i<n; i++)
    {
        TotalUnitsofWater += WaterLevelonEach[i];
    }
    return TotalUnitsofWater;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long height[n];
        for(int i=0; i<n; i++) 
            cin>>height[i];
        
        long totalWaterTrappedBwBlocks = RainWaterTrapping(height, n);
        cout<< totalWaterTrappedBwBlocks <<endl;
    }
}

//can also be implemented using stack (like MAH)