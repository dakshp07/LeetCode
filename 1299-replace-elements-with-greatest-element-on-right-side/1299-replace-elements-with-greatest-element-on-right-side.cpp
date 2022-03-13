class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // TLE Code:
        // vector<int> res;
        // for(int i=0; i<arr.size()-1; i++)
        // {
        //     int j=i+1, temp=INT_MIN;
        //     while(j<arr.size())
        //     {
        //         temp=max(arr[j], temp);
        //         j++;
        //     }
        //     res.push_back(temp);
        // }
        // res.push_back(-1);
        // return res;
        
        // STL Code:
        vector<int> res;
        for(int i=0; i<arr.size()-1; i++)
        {
            res.push_back(*max_element(arr.begin()+i+1, arr.end()));
        }
        res.push_back(-1);
        return res;
    }
};