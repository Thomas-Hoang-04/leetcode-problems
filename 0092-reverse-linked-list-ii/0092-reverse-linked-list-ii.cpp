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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        int t = left;
        ListNode* p = head;
        ListNode* temp = NULL;
        ListNode* st = NULL;
        while (left > 1) {
            if (left == 2) st = p;
            p = p->next;
            left--;
            right--;
        }
        ListNode* e = p;
        while (right > 0 && p != NULL) {
            if (right == 1 && st != NULL) st->next = p;
            if (right == 1 && t == 1) head = p;
            ListNode* memo = p->next;
            p->next = temp;
            temp = p;
            p = memo;
            right--;
        } 
        e->next = p;
        return head;
    }
};