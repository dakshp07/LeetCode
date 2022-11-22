class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // in two sum normal question we didnt had array sorted so we used map approach
        // map approach for two sum normal one: store ele,index and look for target-ele
        // but here the array is already sorted so we use two pointers here
        int left=0, right=numbers.size()-1;
        while(left<right)
        {
            if(numbers[left]+numbers[right]<target)
            {
                left++;
            }
            else if(numbers[left]+numbers[right]>target)
            {
                right--;
            }
            else if(numbers[left]+numbers[right]==target)
            {
                return {left+1, right+1};
            }
        }
        return {-1, -1};
    }
};