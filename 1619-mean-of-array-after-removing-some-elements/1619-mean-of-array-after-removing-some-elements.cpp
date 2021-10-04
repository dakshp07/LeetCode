class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int length=arr.size();
        double trim_length=0.05*(length);
        double sum=0;
        double mean=0.0;
        for(int i=trim_length; i<length-trim_length; i++)
        {
            sum+=arr[i];
            mean=sum/(length-(trim_length*2));
        }
        return mean;
    }
};