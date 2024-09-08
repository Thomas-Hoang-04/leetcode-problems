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
#pragma GCC optimize(O3, "unroll-loops")
/*#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")*/

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        ListNode* curr = head;
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
                if (head) head = head->next;
                cnt--;
            }
            if (curr) curr->next = nullptr;
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();