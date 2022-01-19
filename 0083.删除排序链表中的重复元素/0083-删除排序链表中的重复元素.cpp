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
    void deleteNext(ListNode* ptr)
    {
        ListNode* pendingDelete = ptr->next;
        ptr->next=pendingDelete->next;
        delete pendingDelete;
        pendingDelete=nullptr;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr=head;
        while(ptr && ptr->next)
        {
            if(ptr->val == ptr->next->val) deleteNext(ptr);
            else ptr=ptr->next;
        }
        return head;
    }
};