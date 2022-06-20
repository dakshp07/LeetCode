/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // one way is to go tthrough the list and get its size
        // then you can /2 to get the middle node 
        // traverse to the node and return the ans
        // tc: O(n)+O(n/2)
        // use tortoise method, similar to 1d array to return middle
        ListNode* slow=head; 
        ListNode* fast=head; // declare slow, fast at head
        while(fast!=NULL && fast->next!=NULL) // travese till we reach end or traverse till the next is last
        {
            slow=slow->next; // slow reaches next
            fast=fast->next->next; // fast travels 2* times of slow
        }
        return slow; // slow will have the middle element
    }
};