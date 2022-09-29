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
    // reverse function
    ListNode* reverseList(ListNode* head){
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL)
        {
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        // one approach is to put all the values in an array and see if that array is palindrome
        // tc: O(2*n) (O(n) to put in array from list, another O(n) to check palindrome) and space will be O(n)
        // one of the approach is to use a stack and put all node in stack
        // and empty it as soon as we see the top==current node
        // if our stack has just one ele or 0 ele then we return true
        // tc: O(n) and sc: O(n)
        // smart appraoch is to use middle+reverse
        // tc: O(n/2) for middle + O(n/2) to reverse right half + O(n/2) to compare and O(n/2) to go to middle and O(n/2) to reverse
        // the last are optional and needed if you want to return the head
        // so original tc is O(n/2+n/2+n/2)=O(3n/2) and space is O(1)
        if(head==NULL || head->next==NULL)
        {
            return true; // empty list is a palindrome too
        }
        ListNode *slow=head;
        ListNode *fast=head; // slow moves one step, fast moves two times of slow
        // now below while function is to find middle
        // find middle func:
        while(fast->next!=NULL && fast->next->next!=NULL) // we traverse till fast reaches end
        {
            slow=slow->next; // one step
            fast=fast->next->next; // two times
        }
        // now we use reverse func to revrse the other half
        slow->next=reverseList(slow->next); // slow has middle, so now reverse list after middle
        slow=slow->next;
        // now we traverse the half thats reversed now
        while(slow!=NULL)
        {
            // and check if head==slow
            if(head->val!=slow->val) // check if the val at head and val at slow is not equal
            {
                return false; // as in that case it isnt a palindrome
            }
            // move nodes if they are matching
            head=head->next; // move head
            slow=slow->next; // move slow
        }
        return true; // if they never break means its palindrome
    }
};