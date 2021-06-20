/* In a project, you have a list of required skills req_skills, and a list of people. 
The ith person people[i] contains a list of skills that the person has.
Consider a sufficient team: a set of people such that for every required skill in req_skills, 
there is at least one person in the team who has that skill. We can represent these teams by the index of each person.
For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].
Return any sufficient team of the smallest possible size, represented by the index of each person. 
You may return the answer in any order. It is guaranteed an answer exists.*/


//TLE in leetcode
class Solution {
public:
    vector<int> minPeopleSet;
    
    void solve(vector<int>& peopleSkillMask, int numSkills, int currentPerson, vector<int> peopleSet, int SkillMask)
    {
        if(currentPerson == peopleSkillMask.size())
        {
            if(SkillMask == (1<<numSkills)-1) //SkillMask == 111111
            {
                if(minPeopleSet.size()==0 || peopleSet.size() <= minPeopleSet.size())
                {
                    minPeopleSet = peopleSet;
                }
            }
            return;
        }
        solve( peopleSkillMask, numSkills, currentPerson+1 , peopleSet, SkillMask );
        
        peopleSet.push_back(currentPerson);
        solve( peopleSkillMask, numSkills, currentPerson+1 , peopleSet, (SkillMask|peopleSkillMask[currentPerson]) );
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) 
    {
        unordered_map<string, int> skillsMap;
        int numSkills = req_skills.size();
        for(int i=0; i<numSkills; i++)
        {
            skillsMap[req_skills[i]] = i;
        }
    /*  skillsMap=
            <"algorithms",0>
            <"math", 1>
            <"java", 2>
            <"reactjs", 3>
            <"csharp", 4>
            <"aws", 5> */

        int numPeople = people.size();
        vector<int> peopleSkillMask(numPeople);
        for(int i=0; i<people.size(); i++)
        {
            for(string x: people[i])
            {
                int mappedNum = skillsMap[x];
                peopleSkillMask[i] = peopleSkillMask[i] | (1<<mappedNum);
            }
        }
    /*  
        people =                                 peopleSkillMask=
        0th [ ["algorithms","math","java"],          0 0 0 1 1 1
        1st   ["algorithms","math","reactjs"],       0 0 1 0 1 1
        2nd   ["java","csharp","aws"],               1 1 0 1 0 0
        3rd   ["reactjs","csharp"],                  0 1 1 0 0 0
        4th   ["csharp","math"],                     0 1 0 0 1 0
        5th   ["aws","java"]    ]                    1 0 0 1 0 0
                                                     5/4/3/2/1/0th bit mapped with repective skills */
        
        solve(peopleSkillMask, numSkills, 0, vector<int>(), 0);

        return minPeopleSet;
    }
};
/*
[1,4,5,]
[1,3,5,]
[1,3,4,5,]
[1,2,] -------------------> smallest sufficient team
[1,2,5,]
[1,2,4,]
[1,2,4,5,]
[1,2,3,]
[1,2,3,5,]
[1,2,3,4,]
[1,2,3,4,5,]
[0,3,5,]
[0,3,4,5,]
[0,2,3,]
[0,2,3,5,]
[0,2,3,4,]
[0,2,3,4,5,]
[0,1,4,5,]
[0,1,3,5,]
[0,1,3,4,5,]
[0,1,2,]
[0,1,2,5,]
[0,1,2,4,]
[0,1,2,4,5,]
[0,1,2,3,]
[0,1,2,3,5,]
[0,1,2,3,4,]
[0,1,2,3,4,5,] */
