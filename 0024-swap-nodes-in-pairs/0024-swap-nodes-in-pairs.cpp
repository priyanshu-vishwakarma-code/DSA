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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* currnode = head;
        ListNode* nextnode = head->next;
        ListNode* nexthead = nextnode->next;

        nextnode->next = currnode;  // step 1
        ListNode* newnexthead = swapPairs(nexthead);
        currnode->next = newnexthead;

        return nextnode;
    }
};