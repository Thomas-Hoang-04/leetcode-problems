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
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* t = head->next;
        ListNode* ans = head;
        int sum;
    while (t) {
        sum = 0;
        while (t->val) {
            sum += t->val;
            t = t->next;
        }
        t = t->next;
        head->val = sum;
        if (!t) head->next = nullptr;
        else head = head->next;
    }
    return ans;
    }
};
