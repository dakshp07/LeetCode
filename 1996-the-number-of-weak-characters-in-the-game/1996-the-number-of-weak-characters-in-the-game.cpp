class Solution {
public:
    static bool cmpr(vector<int> &a, vector<int> &b)
    {
        // if attack value are same
        if(a[0]==b[0])
        {
            return a[1]>b[1];
        }
        // sort on basis of attack
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        // lets sort the things on the basis of the attributes
        sort(properties.begin(), properties.end(), cmpr);
        // now for any i every ele behind it has >attack
        // so we need to check only def and reduce that cnt by 1 if i+1 has less def power
        // we store the max def we saw till now and if any character has less def than it we increment ans
        // if any char has >def we update the value of max def
        int max_def=INT_MIN;
        int ans=0;
        for(int i=properties.size()-1; i>=0; i--)
        {
            if(properties[i][1]<max_def) ans++;
            max_def=max(max_def, properties[i][1]);
        }
        return ans;
    }
};