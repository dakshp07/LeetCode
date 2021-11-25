class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int len1=firstList.size();
        int len2=secondList.size();
        int i=0;
        int j=0;
        vector<vector<int>> res;
        while(i<len1 && j<len2)
        {
            if(firstList[i][0]<=secondList[j][1] && firstList[i][1]>=secondList[j][0])
            {
                int fir=max(firstList[i][0], secondList[j][0]);
                int sec=min(firstList[i][1], secondList[j][1]);
                res.push_back({fir, sec});
            }
            firstList[i][1]<secondList[j][1] ? i++ : j++;
        }
        return res;
    }
};