class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedInterval;
        
        if(intervals.size()==0)
            return mergedInterval;
        
        sort(intervals.begin(),intervals.end());
        
        vector<int> tempInterval = intervals[0];
        
        for(auto interval : intervals){
            
            if(interval[0] <= tempInterval[1] )
                tempInterval[1] = max(interval[1],tempInterval[1]);
            
            else { mergedInterval.push_back(tempInterval); tempInterval=interval; }
            
        }
        
        mergedInterval.push_back(tempInterval);
        return mergedInterval;
    }
};