class Solution {
public:
    // sorting function
    static bool cmpr(vector<int> a, vector<int> b)
    {
        return a[1]<b[1]; // b should be greater than a, hence increasing
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        // first we sort the array according to increase in time
        // then we check the course duration if we can pick it or not
        // if we can pick we take it
        // If the course cannot be completed in stipulated time, then we have to check if there is any course that is already completed and is taking more duration than the current course (greedy approach). If there is such a course that is already completed and takes more time than current course, then we remove that course from our result set and include the new course
        sort(courses.begin(), courses.end(), cmpr); // sort acc to cmpr
        priority_queue<int> pq; // to store included courses in order
        int curr_time=0; // to see if a given course can be completed
        for(int i=0; i<courses.size(); i++)
        {
            // if the current course can be finished before or at the same time as given
            if(courses[i][0]+curr_time<=courses[i][1])
            {
                // we push it in queue and add time to curr_time
                pq.push(courses[i][0]);
                curr_time+=courses[i][0];
            }
            // There is a course already inlcluded which has greater duration than this course
            else if(!pq.empty() && pq.top()>courses[i][0])
            {
                // Here we pop that highest duration course and insert new duration... we also decrease our current time accordingly as addition of better course will decrease the duration time
                curr_time-=pq.top()-courses[i][0];
                pq.pop();
                pq.push(courses[i][0]);
            }
        }
        //Since our priority queue contains all the completed courses, we return its size...
        return pq.size();
    }
};