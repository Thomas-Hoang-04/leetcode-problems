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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDis = INT_MAX, minPos = 0, lastCrit = minPos, currPos = 2;
        ListNode* prev = head;
        head = head->next;
        while (head->next) {
            if ((head->val > prev->val && head->val > head->next->val) || (head->val < prev->val && head->val < head->next->val)) {
                if (minPos == 0) minPos = currPos;
                else minDis = min(minDis, currPos - lastCrit);
                lastCrit = currPos;
            }
            currPos++;
            prev = head;
            head = head->next;
        } 
        if (minDis == INT_MAX) return { -1, -1 };
        return { minDis, lastCrit - minPos };
    }
};
