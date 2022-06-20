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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // the question is easy as it expects you to return a new list
        // we will try to do this in place as well
        ListNode *dummy, *temp; // we will move temp
        dummy=new ListNode();
        temp=dummy;
        while(list1 && list2) // traverse the whole length of list1 and 2
        {
            if(list1->val<list2->val) // if list1 val is smaller we put it first
            {
                temp->next=list1;
                list1=list1->next;
            }
            else // if list2 val is smaller we put it first
            {
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next; // updating the list
        }
        if(list1) temp->next=list1;
        if(list2) temp->next=list2;
        return dummy->next;
    }
};