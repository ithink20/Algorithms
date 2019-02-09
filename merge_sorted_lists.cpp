/**
 * author: @vikasc
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *current = new ListNode(0);
        ListNode *merged = current;
        while(l1 && l2) {
            if (l1->val <= l2->val) {
                current->next = l1;
                current = l1;
                l1 = l1 -> next;
            } else {
                current->next = l2;
                current = l2;
                l2 = l2 -> next;
            }
        }
        if (l1) current->next = l1;
        if (l2) current->next = l2;
        merged = merged->next;
        return merged;
    }
};