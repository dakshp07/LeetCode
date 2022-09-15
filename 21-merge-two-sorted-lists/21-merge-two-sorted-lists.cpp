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
        // since we need to return a new list we keep two pointers
        // one will be the new list and the other pointer will be used for traversing
        ListNode* newList, *temp;
        newList=new ListNode(); // initialize the head
        temp=newList; // temp will be used to add
        while(list1!=NULL && list2!=NULL) // we traverse entire of list1 and list2
        {
            // now we check the value of both list
            // if list1->val>list2->val we add list2->val first
            if(list1->val>list2->val)
            {
                temp->next=list2; // add the node in list
                list2=list2->next; // move ahead in list 2
                temp=temp->next; // move ahead in new list too
            }
            else
            {
                temp->next=list1;
                list1=list1->next;
                temp=temp->next;
            }
        }
        // if we still have some nodes left we add them in new list
        if(list1!=NULL) 
        {
            temp->next=list1;
            list1=list1->next;
        }
        if(list2!=NULL) 
        {
            temp->next=list2;
            list2=list2->next;
        }
        return newList->next; // return head of new list
    }
};