class Solution {
public:
    string getPermutation(int n, int k) {
        // brute force is to generate all n! and sort the data structure and return the k-1 permutations
         // tc: O(n!) to find the permutations and O(n) will be used to store them and O(n!logn) to sort
        // the tc will be very very high
        // lets see optimal solution
        // refer striver video for mathematical calculations
        // tc: O(n^2) ad sc: O(n)
        int fact=1;
        vector<int> nums;
        for(int i=1; i<n; i++)
        {
            fact*=i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string ans="";
        k=k-1;
        while(true)
        {
            ans=ans+to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0)
            {
                break;
            }
            k=k%fact;
            fact=fact/nums.size();
        }
        return ans;
    }
};