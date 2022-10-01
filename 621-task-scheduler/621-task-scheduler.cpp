class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // lets store all tasks in an fre arr
        vector<int> freq(26, 0);
        for(int i=0; i<tasks.size(); i++)
        {
            freq[tasks[i]-'A']++;
        }
        // now we sort the array to get the max value at end
        sort(freq.begin(), freq.end());
        // now the max value will be at an index 25
        int max_val=freq[25]-1; // we subtract one because once we reach to the last task in tasks array we dont have wait
        // so for every task the no of slots we need to fill is at max max_val*n
        int idle_slots=max_val*n;
        // now we assume that all these slots are idle
        // now we fill these slots with tasks
        // loop for behind of freq array
        for(int i=24; i>=0; i--)
        {
            idle_slots-=min(freq[i], max_val);
        }
        // so now ans will be
        // if there are any idle slots then ans is the length of task array
        // or else the ans will be idle_slot+task arr length
        return idle_slots>0 ? idle_slots+tasks.size() : tasks.size();
    }
};