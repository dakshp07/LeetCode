class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        // greedy karo
        int cnt=0;
        vector<int> diffs;
        for(int i=0; i<rocks.size(); i++)
        {
            int diff=capacity[i]-rocks[i];
            // zero matlab already done
            if(diff==0) cnt++;
            // warna vector main daalo
            else diffs.push_back(diff);
        }
        // sort karo
        sort(diffs.begin(), diffs.end());
        for(int i=0; i<diffs.size(); i++)
        {
            // additonal zyaada hone chaiye diff se and should be greater than zero
            if(additionalRocks>0 && diffs[i]<=additionalRocks)
            {
                additionalRocks-=diffs[i];
                cnt++;
            }
        }
        return cnt;
    }
};