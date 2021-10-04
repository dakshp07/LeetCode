class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int length=heights.size();
        vector<int> expected(length);
        expected=heights;
        sort(expected.begin(), expected.end());
        int count=0;
        for(int i=0; i<length; i++)
        {
            if(expected[i]!=heights[i])
            {
                count+=1;
            }
        }
        return count;
    }
};