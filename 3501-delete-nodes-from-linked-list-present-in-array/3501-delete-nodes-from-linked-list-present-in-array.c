/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* ans = dummy;
    bool map[100001] = {0};
    while (numsSize--) map[*nums++] = 1;
    while (head) {
        if (map[head->val]) dummy->next = head->next; 
        else dummy = dummy->next;
        head = head->next;
    }
    return ans->next;
}