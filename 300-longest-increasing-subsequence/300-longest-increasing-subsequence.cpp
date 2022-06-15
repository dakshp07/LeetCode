class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // tabulation method
        int n=nums.size();
        int mx=1;
        vector<int> dp(n, 1); // dp of size n
        // dp[i]=signifies the lis that ends at i
        for(int i=0; i<n; i++) // starting se end taak chalo
        {
            for(int prev=0; prev<i; prev++) // or prev ka track rakho
            {
                if(nums[prev]<nums[i]) // can my prev nums be a part of curr ?
                {
                    dp[i]=max(dp[i], 1+dp[prev]); // if yes then my lis now +1 of the prev lis
                }
            }
            mx=max(mx, dp[i]); // puri dp ka max is my ans
        }
        return mx;
    }
};


// Print the lis too:
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         // tabulation method
//         int n=nums.size();
//         int mx=1;
//         vector<int> dp(n, 1); // dp of size n
//         vector<int> hash(n);
//         int last_index=0;
//         // dp[i]=signifies the lis that ends at i
//         for(int i=0; i<n; i++) // starting se end taak chalo
//         {
//             hash[i]=i;
//             for(int prev=0; prev<i; prev++) // or prev ka track rakho
//             {
//                 if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]) // can my prev nums be a part of curr ?
//                 {
//                     dp[i]= 1+dp[prev]; // if yes then my lis now +1 of the prev lis
//                     hash[i]=prev;
//                 }
//             }
//             if(dp[i]>mx)
//             {
//                 mx=dp[i];
//                 last_index=i;
//             }
//         }
//         vector<int> temp;
//         temp.push_back(nums[last_index]);
//         while(hash[last_index]!=last_index)
//         {
//             last_index=hash[last_index];
//             temp.push_back(nums[last_index]);
//         }
//         reverse(temp.begin(), temp.end());
//         for(auto i: temp) cout<<i<<" ";
//         cout<<endl;
//         return mx;
//     }
// };