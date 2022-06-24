class Solution {
public:
    int trap(vector<int>& height) {
        // brute force will be to find the water traped for every index
        // formula is: min(max building size in left, max building size in right)-size of current building
        // for left max we will be going from 0 to i and for right max we will be going from i to n-1
        // tc: O(n^2) as its nested and sc will be O(1)
        // we saw that we are repeating the calculation of left max, right max instead we can store them in some left prefix sum array, right prefix sum array respectively
        // left prefix sum array will store left max building size 
        // right prefix sum array will store right max building size 
        // O(n) for left prefix+O(n) for right prefix and O(n) for one whole traversal~=O(N)
        // sc: O(2n) beacause of two arrays
        // lets remove the extra space
        // we keep left at 0 and right at n-1
        // we also keep a left max and right max to keep hold of the max values
        // if the value at left is less than or equal to value at right and left_max is bigger than the curr value we dont update and move forward
        // we update left_max in other case and move left
        // tc: O(n) and sc: O(1)
        int left=0, right=height.size()-1;
        int res=0, left_max=0, right_max=0;
        while(left<=right)
        {
            // now if height of left building is equal to right
            if(height[left]<=height[right])
            {
                // we check the value of left max
                if(height[left]>=left_max) left_max=height[left];
                // if left max is bigger then we found the water from left
                else res+=left_max-height[left];
                // update left
                left++;
            }
            else
            {
                // check right side with right max
                if(height[right]>=right_max)
                {
                    // this means its time to update right max
                    right_max=height[right];
                }
                // if its smaller
                else res+=right_max-height[right];
                // update right
                right--;
            }
        }
        return res;
    }
};