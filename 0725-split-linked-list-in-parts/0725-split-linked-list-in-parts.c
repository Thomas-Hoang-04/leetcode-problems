/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k,
                                   int* returnSize) {
    struct ListNode** ans = (struct ListNode**)malloc(k * sizeof(struct ListNode*));
    *returnSize = k;
    struct ListNode* curr = head;
    int cnt = 0;
    while (curr) {
        cnt++;
        curr = curr->next;
    }
    int step = cnt / k, rem = cnt % k;
    curr = head;
    for (int i = 0; i < k; i++) {
        ans[i] = head;
        cnt = step;
        if (rem > 0) {
            rem--;
            cnt++;
        }
        while (cnt > 0) {
            curr = head;
            if (head)
                head = head->next;
            cnt--;
        }
        if (curr) curr->next = NULL;
    }
    return ans;
}