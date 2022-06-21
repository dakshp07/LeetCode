/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // basic approach hogi ki set use karo to find the cycle
        // tc: O(n) and space is O(n)
        // fast and slow use karenge
        // step1: find collision by moving slow by 1 and fast by 2
        // step2: now we will find the starting point, add new pointer and move it, slow by one step
        // if they collide then it is the starting point of cycle
        if(head==NULL || head->next==NULL) // if we are the last or the next is last
        {
            return NULL;
        }
        ListNode *slow=head; // takes one step at a time
        ListNode *fast=head; // takes two step at a time
        ListNode *entry=head; // starts a lil late
        while(fast->next && fast->next->next)
        {
            slow=slow->next; // 1 step
            fast=fast->next->next; // 2 step
            if(slow==fast) // if there's a cycle
            {
                // now our entry ptr will come
                while(slow!=entry) // will traverse till they collide
                {
                    slow=slow->next; // 1 step
                    entry=entry->next; // 1 step
                }
                return entry;
            }
        }
        return NULL;
    }
};