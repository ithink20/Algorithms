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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        for (int N = lists.size(); N > 1; N = (N + 1)/2) {
            for (int i = 0; i < N / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[N - 1 - i]);
            }
        }
        return lists[0];
    }
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