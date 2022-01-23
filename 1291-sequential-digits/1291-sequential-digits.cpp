class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        string digits="123456789";
        string lo=to_string(low);
        string hi=to_string(high);
        for(int i=lo.size(); i<=hi.size(); i++)
        {
            for(int j=0; j<10-i; j++)
            {
                int num=stoi(digits.substr(j, i));
                if(num>=low && num<=high)
                {
                    res.push_back(num);
                }
            }
        }
        return res;
    }
};