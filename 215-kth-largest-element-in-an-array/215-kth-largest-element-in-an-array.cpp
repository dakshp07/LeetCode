class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sorting karne se O(nlogn) lagega
        // ek traversal main hoga:
        // priority queue use karte hain
        // reason ye ki sab order main rakhegi woh
        priority_queue<int> pq;
        for(int i=0; i<nums.size(); i++)
        {
            pq.push(nums[i]);
        }
        k--; // 0 indexing
        while(k!=0) // pop karo jab taak hum kth tak na aajaye
        {
            pq.pop();
            k--;
        }
        return pq.top();
    }
};
