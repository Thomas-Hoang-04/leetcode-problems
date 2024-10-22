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
class Solution {
public:
    long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long, vector<long>, greater<long>> pq;

        queue<TreeNode*> bfs;
        bfs.push(root);
        int size;
        long sum;
        TreeNode* curr = nullptr;
        while (!bfs.empty()) {
            size = bfs.size();
            sum = 0;
            for (;size;size--) {
                curr = bfs.front();
                bfs.pop();
                sum += curr->val;
                if (curr->left) bfs.push(curr->left);
                if (curr->right) bfs.push(curr->right);
            }
            pq.push(sum);
            if (pq.size() > k) pq.pop();
        }
        if (pq.size() < k) return -1;
        return pq.top();
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();