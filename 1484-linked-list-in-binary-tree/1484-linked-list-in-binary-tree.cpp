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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#pragma GCC optimize(O3, "unroll-loops")

class Solution {
private:
    vector<int> pattern, prefixTab = { 0 };
    bool searchTree(TreeNode* root, ListNode* head) {
        if (!head) return true;
        if (!root || (root->val != head->val)) return false;
        return searchTree(root->left, head->next) || searchTree(root->right, head->next);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        bool res = searchTree(root, head);

        res |= (isSubPath(head, root->left) || isSubPath(head, root->right));

        return res;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();