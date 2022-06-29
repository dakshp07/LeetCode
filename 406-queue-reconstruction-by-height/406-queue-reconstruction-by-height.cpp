class Solution {
public:
    static bool cmpr(vector<int> a, vector<int> b)
    {
        // Sort the array in decreasing order of their heights and if two people have same height, sort them in increasing order of their [1] index
        if(a[0]==b[0])
        {
            return a[1]<b[1];
        }
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // lets sort the arr according to the conditions mentioned in question
        sort(people.begin(), people.end(), cmpr);
        // now we check [1] of every element and put them at that positions
        vector<vector<int>> res;
        for(int i=0; i<people.size(); i++)
        {
            int index=people[i][1]; // index where we want to keep our ele
            res.insert(res.begin()+index, people[i]);
        }
        return res;
    }
};