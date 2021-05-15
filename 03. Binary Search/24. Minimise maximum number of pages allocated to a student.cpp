/*Given number of pages in n different books and m students.
The books are arranged in ascending order of number of pages. 
 Every student is assigned to read some consecutive books.  The task is to assign books 
 in such a way that the maximum number of pages assigned to a student is minimum.
Example :
Input : pages[] = {12, 34, 67, 90}
        m = 2
Output : 113
Explanation:
There are 2 number of students. Books can be distributed 
in following fashion : 
  1) [12] and [34, 67, 90]
      Max number of pages is allocated to student 
      2 with 34 + 67 + 90 = 191 pages
  2) [12, 34] and [67, 90]
      Max number of pages is allocated to student
      2 with 67 + 90 = 157 pages 
  3) [12, 34, 67] and [90]
      Max number of pages is allocated to student 
      1 with 12 + 34 + 67 = 113 pages
Of the 3 cases, Option 3 has the minimum pages = 113.   */
///Time Complexity: O(NLogN). 

#include <iostream>
using namespace std;

pair<int,long long> MaxandSum(int pages[], int n)
{
    pair<int,long long> ms;
    int max = 0;
    long long sum = 0;
    for(int i=0; i<n; i++)
    {
        if(pages[i] > max)
            max = pages[i];
        sum += pages[i];
    }
    ms.first = max;
    ms.second = sum;
    return ms;
}

bool isFeasibleSol(int pages[], int n, int stu, long long MaxPagesPerStu)
{
    int stu_count = 1;
    
    long long SumPagesToAStu = 0;
    for (int i=0; i<n; i++)
    {
        SumPagesToAStu += pages[i];
        if(SumPagesToAStu > MaxPagesPerStu)
        {
            stu_count ++;
            SumPagesToAStu = pages[i]; //allocating last remaining books to next student
        }
            
        if(stu_count > stu)
            return false;
    }
    return true;
}


int MinimizeMaxPagesToAStu(int pages[], int n, int stu) 
{
    if(n < stu) //since Each student has to be allocated atleast one book
        return -1; //no. of books shoulds always be >= no. of students
        
    int maxpages = MaxandSum(pages, n).first;
    long long sumofallpages = MaxandSum(pages, n).second;
    
    int low = maxpages;
    long long high = sumofallpages;
    
    int res = -1;
    while(low <= high)
    {
        long long mid = low + (high - low)/2; //mid ~ upper limit of no. of pages per student
        
        if(isFeasibleSol(pages, n, stu, mid) == true)
        {
            res = mid;
            high = mid-1; //search with lower mid ~ MaxPagesPerStuLimit //go to left part
        }
        else if(isFeasibleSol(pages, n, stu, mid) == false)
        {
            low = mid + 1; //search with higher mid ~ MaxPagesPerStuLimit //go to right part
        }
    }
    return res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //Number of Books
        int pages[n];
        for (int i=0; i<n; i++) 
            cin>>pages[i]; //Pages in each Book
        int stu;
        cin>>stu; //Number of Students
        
        int ans = MinimizeMaxPagesToAStu(pages, n , stu);
        cout<< ans <<endl;
    }
}