class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> freq_tar(1001, 0), freq_arr(1001, 0);
        for(int i=0; i<target.size(); i++)
        {
            freq_tar[target[i]]++;
        }
        for(int i=0; i<arr.size(); i++)
        {
            freq_arr[arr[i]]++;
        }
        return freq_tar==freq_arr;
    }
};