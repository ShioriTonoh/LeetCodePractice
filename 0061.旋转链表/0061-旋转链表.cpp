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
        if(!head || !head->next || !k)
        {
            return head;
        }
        ListNode* tail=nullptr;
        int listLength=1;
        for(tail=head;tail->next;tail=tail->next)
        {
            ++listLength;
        }
        cout<<listLength<<endl;
        tail->next=head;
        k%=listLength;
        if(k)
        {
            for(int i=0;i<listLength-k;++i)
            {
                head=head->next;
                tail=tail->next;
            }
        }
        tail->next=nullptr;
        return head;
    }
};