class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int sand_length=sandwiches.size();
        int stu_length=students.size();
        int ones=0;
        int zeroes=0;
        for(int i=0; i<stu_length; i++)
        {
            if(students[i]==0)
            {
                zeroes++;
            }
            else
            {
                ones++;
            }
        }
        for(int i=0; i<stu_length; i++)
        {
            if(sandwiches[i]==0)
            {
                if(zeroes==0)
                {
                    return ones;
                }
                zeroes--;
            }
            else
            {
                if(ones==0)
                {
                    return zeroes;
                }
                ones--;
            }
        }
        return 0;
    }
};