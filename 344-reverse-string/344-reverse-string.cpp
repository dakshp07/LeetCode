class Solution {
public:
    void reverseString(vector<char>& s) {
        // one is to use the inbuilt reverse function
        // but we use two pointers
        int left=0;
        int right=s.size()-1;
        while(left<=right)
        {
            swap(s[right], s[left]);
            left++;
            right--;
        }
    }
};