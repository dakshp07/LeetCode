class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt=0;
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        for(int i=0; i<arr1.size(); i++)
        {
            bool ok=true;
            for(int j=0; j<arr2.size(); j++)
            {
                int dis=abs(arr1[i]-arr2[j]);
                if(dis<=d)
                {
                    ok=false;
                    break;
                }
            }
            if(ok)
            {
                cnt++;
            }
        }
        return cnt;
    }
};