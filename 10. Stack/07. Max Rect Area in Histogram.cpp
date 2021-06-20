//T.C = O(n)
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> iNSL(vector<int> height, int n)
{
   vector<int> v;
   int pseudoindx = -1;
   stack<pair<int,int>> st;

   for(int i=0; i<n; i++) //L to R traversal in height
   {
        if(st.size()==0)
            v.push_back(pseudoindx);
        else if(st.size()>0 && st.top().first<height[i])
            v.push_back(st.top().second);
        else if(st.size()>0 && st.top().first>=height[i])
        {
            while(st.size()>0 && st.top().first>=height[i])
            {
                st.pop();
            }//loop ends if st is empty or st.top()<height[i] found
            if(st.size()==0)
                v.push_back(pseudoindx);
            else// if(st.top().first < height[i])
                v.push_back(st.top().second);
        }
        st.push({height[i],i});//pushing a pair i.e, NSL element and its index
   }
   return v; //no reverse req. //vector v gives the "index of NSL" of each height[i]
}
vector<int> iNSR(vector<int> height, int n)
{
   vector<int> v;
   int pseudoindx = n;
   stack<pair<int,int>> st;

   for(int i=n-1; i>=0; i--) //R to L traversal in height
   {
        if(st.size()==0)
            v.push_back(pseudoindx);
        else if(st.size()>0 && st.top().first<height[i])
            v.push_back(st.top().second);
        else if(st.size()>0 && st.top().first>=height[i])
        {
            while(st.size()>0 && st.top().first>=height[i])
            {
                st.pop();
            }//loop ends if st is empty or st.top()<height[i] found
            if(st.size()==0)
                v.push_back(pseudoindx);
            else// if(st.top()<height[i])
                v.push_back(st.top().second);
        }
        st.push({height[i],i});//pushing a pair i.e, NSR element and its index
   }
   reverse(v.begin(), v.end());
   return v; //vector v gives the "index of NSR" of each height[i]
}

long largestRectangle(vector<long> area, int n) 
{
    long max_area=0;
    for (int i=0; i<n; i++)
    {
        if(area[i]>max_area)
            max_area = area[i];
    }
    return max_area;
}


int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i=0; i<n; i++) 
    {
        cin>>height[i];
    }
    vector<int> left = iNSL(height,n);
    vector<int> right = iNSR(height,n);
    vector<int> width(n);
    for (int i=0; i<n; i++)
    {
        width[i] = right[i]-left[i]-1;
    }
    vector<long> area(n);
    for (int i=0; i<n; i++)
    {
        area[i] = height[i]*width[i]; //area[i] denotes MAX AREA of possible rectangle w.r.t each heigth[i] & its width[i]
    }
    long result = largestRectangle(area, n); //max of all area[i]
    cout<< result <<endl;
    return 0;
}