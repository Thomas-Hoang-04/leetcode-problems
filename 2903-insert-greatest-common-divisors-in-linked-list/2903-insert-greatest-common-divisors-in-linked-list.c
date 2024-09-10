/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int findGCD(int a, int b) {
    if (!b) return a;
    return findGCD(b, a % b);
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    if (!head->next) return head;
    struct ListNode* l = head;
    struct ListNode* r = head->next;
    struct ListNode* t;
    while (r) {
        t = (struct ListNode*)malloc(sizeof(struct ListNode));
        t->val = findGCD(l->val, r->val);
        t->next = r;
        l->next = t;
        l = r;
        r = r->next;
    }
    return head;
}