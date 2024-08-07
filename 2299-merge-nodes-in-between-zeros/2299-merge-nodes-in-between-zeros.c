/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    if (!head) return head;
    struct ListNode* t = head->next;
    struct ListNode* ans = head;
    int sum;
    while (t) {
        sum = 0;
        while (t->val) {
            sum += t->val;
            t = t->next;
        }
        t = t->next;
        head->val = sum;
        if (!t) head->next = NULL;
        else head = head->next;
    }
    return ans;
}