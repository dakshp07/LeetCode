class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    //     sorting laga ke
    //     sort(nums.begin(), nums.end());
    //     reverse(nums.begin(), nums.end());
    //     for(int i=0; i<nums.size(); i++)
    //     {
    //         if(i+1==k)
    //         {
    //             return nums[i]; 
    //         }
    //     }
    //     return 0;
        
        // priority queue use karke
        priority_queue<int> pq;
        for(int i=0; i<nums.size(); i++)
        {
            pq.push(nums[i]);
        }
        // making k as 0 indexed
        k-=1;
        while(k>0)
        {
            // pop element till we find the top kth ele in queue
            // prioirty queue sorts everything in decreasing order
            pq.pop();
            k--;
        }
        return pq.top();
    } 
};
