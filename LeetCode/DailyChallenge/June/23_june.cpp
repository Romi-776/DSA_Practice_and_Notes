// Course Schedule III - https://leetcode.com/problems/course-schedule-iii/

// T.C = O(NlogN), where N = no. of courses
class Solution
{
    static bool comp(vector<int> &v1, vector<int> &v2)
    {
        return (v1[1] < v2[1]);
    }

public:
    // Solved with the Greedy algorithm where if we can add do a course in the before its last_day then we're going to do it
    // otherwise we'll check that if we have done a course that's time span is greater than the current one then we'll remove
    // that course and do the current course
    int scheduleCourse(vector<vector<int>> &courses)
    {
        // sorting the courses according to the course last_day
        sort(courses.begin(), courses.end(), comp);

        // total days we have spent doing courses till now
        int days = 0;
        // stores the courses with max duration course at top
        priority_queue<int> pq;

        // iterating through all courses
        for (vector<int> course : courses)
        {
            // adding current course into consideration
            days += course[0], pq.push(course[0]);

            // this course couldn't be completed in the specified time limit
            if (days > course[1])
                days -= pq.top(), pq.pop(); // remove the longest duration course from our list
        }

        return pq.size(); // returning total courses taken
    }
};