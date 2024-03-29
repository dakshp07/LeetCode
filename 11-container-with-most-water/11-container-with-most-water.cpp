class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1, max_area=INT_MIN;
        while(left<right)
        {
            if(height[left]>height[right])
            {
                max_area=max(max_area, height[right]*(right-left));
                right--;
            }
            else
            {
                max_area=max(max_area, height[left]*(right-left));
                left++;
            }
        }
        return max_area;
    }
};