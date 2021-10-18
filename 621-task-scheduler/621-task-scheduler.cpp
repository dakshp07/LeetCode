class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq_alpha(26);
        for(int i=0; i<tasks.size(); i++)
        {
            freq_alpha[tasks[i]-'A']++;
        }
        sort(freq_alpha.begin(), freq_alpha.end());
        int max_val=freq_alpha[25]-1;
        int idle=max_val*n;
        for(int i=24; i>=0; i--)
        {
            idle-=min(freq_alpha[i], max_val);
        }
        return idle>0?idle+tasks.size():tasks.size();
    }
};