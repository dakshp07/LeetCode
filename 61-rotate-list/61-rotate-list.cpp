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
    ListNode* rotateRight(ListNode* head, int k) {
        // n=len of list
        // brute force hoga ki pick up last node and put it in front for k times
        // tc O(k*n) (picking last element will take n time and doing it for k times)
        // more optimal: there will be two cases 
        // 1. when k>=len: after doing rotation for n times, we get back original list
        // so for k>=len we will do rotation only for k%n times
        // 2. k<len: we just have to just break the point from k-n position
        // cal n, last->next will be head, and then cal k-n to point to head
        // tc: O(n)+O(n-(n%k))~=O(n) and sc: O(1)
        if(head==NULL || !head->next || k==0) return head; // edge case when we are at last or last second node or k=0
        // lets calc len
        ListNode *curr=head;
        int len=1; // since we are already at head
        while(curr->next)
        {
            len++;
            curr=curr->next;
        }
        // now we will go our node
        curr->next=head;
        k=k%len; // if k>=len
        k=len-k; // if k<len
        while(k--) // traverse till there
        {
            curr=curr->next; 
        }
        // make the new head and break connection
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};