/* There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) 
where S[i] is start time of meeting i and F[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room 
when only one meeting can be held in the meeting room at a particular time? 
Also note start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
Input:
N = 6
S[] = {1,3,0,5,8,5}
F[] = {2,4,6,7,9,9}
Output: 
4   (possibleMeetingsNumber = <1,2,4,5> ) 
First meeting [1, 2] 
Second meeting [3, 4] 
Fourth meeting [5, 7] 
Fifth meeting [8, 9]          */  


//greedy approach which is the same as Activity Selection Problem.
class Solution
{
    struct meeting
    {
        int startTime;
        int endTime;
        int meetingNumber;
    };
    static bool comp(struct meeting &a, struct meeting &b)
    {
        if(a.endTime < b.endTime)
            return true;
        else if(a.endTime > b.endTime)
            return false;
        else if(a.endTime == b.endTime)
        {
            if(a.meetingNumber < b.meetingNumber)
                return true;
            else
                return false;
        }
    }
    
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        struct meeting meet[n];
        
        for(int i=0; i<n; i++)
        {
            meet[i].startTime = start[i];
            meet[i].endTime = end[i];
            meet[i].meetingNumber = i+1;
        }
        sort(meet, meet+n, comp); //w.r.t meeting endTime
        
        
        vector<int> possibleMeetings;
        
        int endLimit = meet[0].endTime;
        possibleMeetings.push_back(meet[0].meetingNumber);
        
        for(int i=1; i<n; i++)
        {
            if(meet[i].startTime > endLimit)
            {
                endLimit = meet[i].endTime;
                possibleMeetings.push_back(meet[i].meetingNumber);
            }
        }
        // for(int x: possibleMeetings)
        //     cout<< x <<","; 
        return possibleMeetings.size();
    }
};



/*
why we have to write static keyword before comparator function in gfg?

So that there is no need of creating an object of the class to call the function, 
you can directly call it */