class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // brute force solution is to check the left smallest and right smallest for every index i
        // store those index. so width: left-right+1
        // height is the a[i]. so area is width * height
        // take the max out of all areas
        // this will take O(n^2) which is not good
        
        // we can use the concept of next smaller ele/next greater ele
        // we will use a stack to keep track of smaller ele in left side abd right side
        // an array will be used to store the indices which has the index of every smaller ele
        // similar array for right side too
        // TC: O(N)+O(N) for one right side and left side
        // take max of right array, left array. area=(left-right+1)*a[i]
        // sc: O(3*N) as we have 2 arrays and one stack
        vector<int> leftsmall(heights.size()), rightsmall(heights.size());
        stack<int> st;
        for(int i=0; i<heights.size(); i++)
        {
            // if we get an ele bigger then our top of stack
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                // we pop
                st.pop();
            }
            if(st.empty()) leftsmall[i]=0; // if still empty means 0 as left small
            else leftsmall[i]=st.top()+1; // push the top
            st.push(i); // push the index
        }
        // clear the stack for right side
        while(!st.empty()) st.pop();
        // repeat for right but traverse from behind
        for(int i=heights.size()-1; i>=0; i--)
        {
            // if we get an ele bigger then our top of stack
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                // we pop
                st.pop();
            }
            if(st.empty()) rightsmall[i]=heights.size()-1; // if still empty means size of arr as right small
            else rightsmall[i]=st.top()-1; // push the top
            st.push(i); // push the index
        }
        int area=0;
        for(int i=0; i<heights.size(); i++)
        {
            area=max(area, heights[i]*(rightsmall[i]-leftsmall[i]+1)); // area
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        // in order to solve this problem we can use the concept of largest rectangle in histogram
        // we can consider each column as one new array and apply the concept
        int max_area=0;
        vector<int> height(matrix[0].size(), 0);
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j]=='1')
                {
                    height[j]++;
                }
                else
                {
                    height[j]=0;
                }
            }
            int area=largestRectangleArea(height);
            max_area=max(max_area, area);
        }
        return max_area;
    }
};