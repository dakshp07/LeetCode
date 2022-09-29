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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // one of the ways could be to find the length of list
        // and then trace back to the nth node
        // and change their connections
        // tc: O(len of list)+O(n)
        // lets reduce the time complexity and do it off in one traversal
        
        // we use slow, fast pointer
        ListNode *slow, *fast, *temp;
        temp=new ListNode();
        temp->next=head; // temp starts from head
        // both slow and fast are at temp position
        fast=temp;
        slow=temp;
        // fast will start from nth pos
        for(int i=0; i<n; i++)
        {
            fast=fast->next;
        }
        // now we run slow, fast till fast->next is null
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        // now slow is at the position where the nth node is
        // so we remove connection
        slow->next=slow->next->next;
        // return temp->next node back as thats our head
        return temp->next;
    }
};