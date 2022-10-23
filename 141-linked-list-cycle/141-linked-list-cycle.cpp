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
    bool hasCycle(ListNode *head) {
        // one of the ways is to use a set and put all nodes in it
        // if we come across any node which is already present in our set we return true
        // tc: O(len of list) and sc: O(n)
        
        // unordered_set<ListNode*> st;
        // ListNode *temp=head;
        // while(temp->next!=NULL)
        // {
        //     if(st.find(temp)!=st.end())
        //     {
        //         return true;
        //     }
        //     st.insert(temp);
        //     temp=temp->next;
        // }
        // return false;
        
        
        // but we can use the tortoise hore algo
        // by keeping a fast, slow ptr. if they meet we return true
        if(head==NULL) return false;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast) return true;
        }
        return false;
    }
};