#include <iostream>
#include <cmath>
using namespace std;

long double area(long x1, long y1, long x2, long y2, long x3, long y3) 
{ 
   return abs((x1*y2 - x2*y1 + x2*y3 - x3*y2 + x3*y1 - x1*y3)/2.0); 
}
int main() 
{
    long TriangleHavingOrigin = 0;
    long N;
    cin>>N;
    while(N--)
    {
        long x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;

        long double areaoftri = area(x1, y1, x2, y2, x3, y3);
        long double area1 = area(0, 0, x2, y2, x3, y3);
        long double area2 = area(x1, y1, 0, 0, x3, y3);
        long double area3 = area(x1, y1, x2, y2, 0, 0);

        if(areaoftri == (area1 + area2 + area3))
            TriangleHavingOrigin++;
    }
    cout<<TriangleHavingOrigin<<endl;
}
