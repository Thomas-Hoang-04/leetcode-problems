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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode();
        ListNode* tail = dummyHead;
        int c = 0, d, d1, d2, sum;

        while (l1 || l2 || c) {
            d1 = l1 ? l1->val : 0;
            d2 = l2 ? l2->val : 0;

            sum = d1 + d2 + c;
            d = sum % 10;
            c = sum / 10;

            ListNode* temp = new ListNode(d);
            tail->next = temp;
            tail = tail->next;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};