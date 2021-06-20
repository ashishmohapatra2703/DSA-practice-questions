/* Given a list of n points on 2D plane, 
the task is to find the K (k < n) closest points to the origin O(0, 0). 
Note: The distance between a point P(x, y) and O(0, 0) using the standard Euclidean Distance.  

Input: [(1, 0), (2, 1), (3, 6), (-5, 2), (1, -4)],   K = 3 
Output: [(1, 0), (2, 1), (1, -4)] 
Explanation: 
Square of Distances of points from origin are 
(1, 0) : 1 
(2, 1) : 5 
(3, 6) : 45 
(-5, 2) : 29 
(1, -4) : 17 
Hence for K = 3, the closest 3 points are (1, 0), (2, 1) & (1, -4)   
 T.C = N*log(K)                           */

class Solution 
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {
        priority_queue<pair<int , pair<int,int>>> maxh;
        
        for(int i=0; i<points.size(); i++)
        {
            maxh.push( {  (points[i][0]*points[i][0]+points[i][1]*points[i][1]) , 
                          {points[i][0] , points[i][1]}   } );
            
            if(maxh.size() > K)
                maxh.pop();
        }
        
        vector<vector<int>> kClosesttoOri;
        while(!maxh.empty())
        {
            vector<int> opPoint = {maxh.top().second.first , maxh.top().second.second};
            kClosesttoOri.push_back(opPoint);
            maxh.pop();
        }
        return kClosesttoOri;
    }
};