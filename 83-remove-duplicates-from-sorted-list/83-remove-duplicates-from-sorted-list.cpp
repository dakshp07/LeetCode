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
    ListNode* deleteDuplicates(ListNode* head) {
        // first we need to find the duplicates
        // we use concept of slow,fast ptrs
        if(head==NULL) return NULL;
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast!=NULL)
        {
            if(slow->val==fast->val)
            {
                // we break the links
                fast=fast->next;
                slow->next=fast;
            }
            else
            {
                // else both go on their path
                slow=fast;
                fast=slow->next;
            }
        }
        return head;
    }
};