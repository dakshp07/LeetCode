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
        // one of the brute way is to find the entire length of linked list
        // and then find the middle but thats brute
        // we can use the concept of fast and slow pointer
        ListNode *fast, *slow;
        // both start from head
        fast=head;
        slow=head;
        // since fast moves 2 times we keep a check if its null or not
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next; // fast moves by 2
            slow=slow->next; // slow moves by 1
        }
        return slow;
    }
};