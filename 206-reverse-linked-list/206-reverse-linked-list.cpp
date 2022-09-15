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
    ListNode* reverseList(ListNode* head) {
        // one of the easiest way is to store the nodes in an array, reverse the array
        // and then create a new list and add those ele of array in list as nodes, return head
        // but thats brute
        // we can do one thing
        
        // step 1: make a new head with null
        ListNode *newHead=NULL; 
        // step 2: traverse the list
        while(head!=NULL)
        {
            // step 2.1: store head->next value
            ListNode *next=head->next;
            // step 2.2: make the head next to new head
            head->next=newHead;
            // step 2.3: the new head will get updated
            newHead=head;
            // step 2.4: the old head stores the value that just got newly connected
            head=next;
        }
        return newHead;
    }
};