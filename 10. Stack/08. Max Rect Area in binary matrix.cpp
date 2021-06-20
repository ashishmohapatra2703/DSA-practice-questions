//both methods are TLE on gfg
/////////////////////////////////////////////////////////////////////// M-1
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
#define MAX 1000

vector<int> iNSR(int height[], int m)
{
    vector<int> v;
    stack<pair<int,int>> st;
    int pseudoindx = m;
    
    for(int i=m-1; i>=0; i--) //R to L traversal in height
    {
        if(st.size()==0)
            v.push_back(pseudoindx);
        else if(st.size()>0 && st.top().first < height[i])
            v.push_back(st.top().second);
        else if(st.size()>0 && st.top().first >= height[i])
        {
            while(st.size()>0 && st.top().first >= height[i])
            {
                st.pop();
            }
            if(st.size()==0)
                v.push_back(pseudoindx);
            else if(st.top().first < height[i])
                v.push_back(st.top().second);
        }
        st.push({height[i] , i});//pushing a pair i.e, NSR element and its index
    }
    reverse(v.begin(), v.end());
    return v;
}
vector<int> iNSL(int height[], int m)
{
    vector<int> v;
    stack<pair<int,int>> st;
    int pseudoindx = -1;
    
    for(int i=0; i<m; i++) //L to R traversal in height
    {
        if(st.size()==0)
            v.push_back(pseudoindx);
        else if(st.size()>0 && st.top().first < height[i])
            v.push_back(st.top().second);
        else if(st.size()>0 && st.top().first >= height[i])
        {
            while(st.size()>0 && st.top().first >= height[i])
            {
                st.pop();
            }//loop ends if st is empty or st.top()<height[i] found
            if(st.size()==0)
                v.push_back(pseudoindx);
            else if(st.top().first < height[i])
                v.push_back(st.top().second);
        }
        st.push({height[i] , i}); //pushing a pair i.e, NSL element and its index
    }
    return v;
}

int MaxAreaofHistogram(int height[], int m)
{
    vector<int> right = iNSR(height, m);
    vector<int> left = iNSL(height, m);
    
    vector<int> width(m);
    for(int i=0; i<m; i++)
    {
        width[i] = right[i]-left[i]-1;
    }
    
    vector<int> area(m);
    for(int i=0; i<m; i++)
    {
        area[i] = height[i]*width[i];
    }
    //area[i] denotes MAX AREA of possible rectangle w.r.t each heigth[i] & its width[i]
    int MaxAreaofHist = 0;
    for(int i=0; i<m; i++)
    {
        MaxAreaofHist = max(MaxAreaofHist, area[i]);
    }
    return  MaxAreaofHist;
}

/*You are required to complete this method*/
int maxArea(int M[MAX][MAX], int n, int m) 
{
    int Max_Area = 0;
    int height[m];
    for(int i=0,j=0 ; j<m; j++) //for first row
    {
        height[j] = M[i][j];
    }
    Max_Area = MaxAreaofHistogram(height, m);
    
    for(int i=1; i<n; i++) //from 2nd row onwards
    {
        for(int j=0 ; j<m; j++)
        {
            if(M[i][j] != 0)
                height[j] += M[i][j];
            else if(M[i][j] == 0)
                height[j] = 0;
        }
        Max_Area = max(Max_Area, MaxAreaofHistogram(height, m));
        //for each row converted to 1-D height[] histogram
    }
    return Max_Area;
}

int main() 
{
    int T;
    cin >> T;
    int M[MAX][MAX];
    while (T--) 
    {
        int n, m;
        cin >> n >> m;
        for (int i=0; i<n; i++) 
        {
            for (int j=0; j<m; j++) 
            {
                cin>>M[i][j];
            }
        }
        int ans = maxArea(M, n, m);
        cout<<ans<<endl;
    }
}


////////////////////////////////////////////////////////////////////////// M-2
//reducing space compexity
#include <iostream>
#include <algorithm>
#include <climits>
#include <stack>
using namespace std;
#define MAX 1000

int MaxAreaofHistogram(int height[], int m)
{
    int v[m];
    stack<pair<int,int>> st;
    
    int pseudoindx = m;
    for(int i=m-1; i>=0; i--) //R to L traversal in height
    {
        if(st.size()==0)
            v[i] = pseudoindx;
        else if(st.size()>0 && st.top().first < height[i])
            v[i] = st.top().second;
        else if(st.size()>0 && st.top().first >= height[i])
        {
            while(st.size()>0 && st.top().first >= height[i])
            {
                st.pop();
            }
            if(st.size()==0)
                v[i] = pseudoindx;
            else if(st.top().first < height[i])
                v[i] = st.top().second;
        }
        st.push({height[i] , i});//pushing a pair i.e, NSR element and its index
    }
    //already iNSR reverse stored in v (from index i to m-1)
    
    while(st.size() != 0)
        st.pop(); //empty the stack to reuse

    pseudoindx = -1;
    for(int i=0; i<m; i++) //L to R traversal in height
    {
        if(st.size()==0)
            v[i] = v[i]- pseudoindx -1;
            //v[i+m] = pseudoindx;
        else if(st.size()>0 && st.top().first < height[i])
            v[i] = v[i]- st.top().second -1;
            //v[i+m] = st.top().second;
        else if(st.size()>0 && st.top().first >= height[i])
        {
            while(st.size()>0 && st.top().first >= height[i])
            {
                st.pop();
            }//loop ends if st is empty or st.top()<height[i] found
            if(st.size()==0)
                v[i] = v[i]- pseudoindx -1;
                //v[i+m] = pseudoindx;
            else if(st.top().first < height[i])
                v[i] = v[i]- st.top().second -1;
                //v[i+m] = st.top().second;
        }
        st.push({height[i] , i}); //pushing a pair i.e, NSL element and its index
    }
    //iNSL stored in v (from index m to 2*m-1)
    
    //for(int i=0; i<m; i++)
    //{
    //    v[i] = v[i]- v[i+m] -1; //width[i] = right[i]-left[i]-1;
    //}
    
    int MaxAreaofHist = INT_MIN;
    for(int i=0; i<m; i++)
    {
        MaxAreaofHist = max(MaxAreaofHist, height[i]*v[i]);
    }//area[i] denotes MAX AREA of possible rectangle w.r.t each heigth[i] & its width[i]
    return  MaxAreaofHist;
}

/*You are required to complete this method*/
int maxArea(int M[MAX][MAX], int n, int m) 
{
    int Max_Area = MaxAreaofHistogram(M[0], m); //for first row
    for(int i=1; i<n; i++)
    {
        for(int j=0 ; j<m; j++)
        {
            if(M[i][j] != 0)
                M[i][j] += M[i-1][j];
        }
        Max_Area = max(Max_Area, MaxAreaofHistogram(M[i] , m));//2nd row onwards
        //for each row converted to 1-D height[] histogram
    }
    return Max_Area;
}

int main() 
{
    int T;
    cin >> T;
    int M[MAX][MAX];
    while (T--) 
    {
        int n, m;
        cin >> n >> m;
        for (int i=0; i<n; i++) 
        {
            for (int j=0; j<m; j++) 
            {
                cin>>M[i][j];
            }
        }
        int ans = maxArea(M, n, m);
        cout<<ans<<endl;
    }
}