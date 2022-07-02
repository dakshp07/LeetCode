class Solution {
public:
    const int MOD=1e9+7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        // in order to maximise area you need max width and max height
        // to get that we can get the max diff b/w 2 cons ele of hori, vert
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        // there are two cases:
        // 1. when the array has more than 1 ele, we take max diff
        // 2. if array has one ele then we can take diff b/w height/width with that ele and it will be max
        // in order to simply our code we will push the h, w in our vectors and then sort them, use for loop to get max diff. this helps in making code small by removing if else loops
        horizontalCuts.push_back(0); // to get the diff from first hori cut we add the start
        horizontalCuts.push_back(h); // to get the diff from last hori cut we add the boundary
        int height=0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        for(int i=1; i<horizontalCuts.size(); i++)
        {
            // get max diff
            height=max(height, horizontalCuts[i]-horizontalCuts[i-1]);
        }
        verticalCuts.push_back(0); // to get the diff from first ver cut we add the start
        verticalCuts.push_back(w); // to get the diff from last ver cut we add the boundary
        int width=0;
        sort(verticalCuts.begin(), verticalCuts.end());
        for(int i=1; i<verticalCuts.size(); i++)
        {
            // get max diff
            width=max(width, verticalCuts[i]-verticalCuts[i-1]);
        }
        return (1LL*width*height)%MOD; // typecast didnt worked so multiply
    }
};