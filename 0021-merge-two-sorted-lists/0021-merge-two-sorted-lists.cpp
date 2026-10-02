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
        if(list1 == NULL && list2==NULL) return NULL;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* curr;
        ListNode* l1;
        ListNode* l2;
        ListNode* ans;

        if(list1->val <= list2->val) curr = list1, ans = list1 , l1 = list1->next , l2 = list2;
        else curr = list2 , ans = list2 , l2 = list2->next , l1 = list1;

        while(l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                curr->next = l1;
                curr = l1;
                l1 = l1->next;
            }else{
                curr->next = l2;
                curr = l2;
                l2 = l2->next;
            }
        }

        if(l1 == NULL){
            curr->next = l2;
        }else if(l2 == NULL){
            curr->next = l1;
        }
                            
        return ans;
    }
};