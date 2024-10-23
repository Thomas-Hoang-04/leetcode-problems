/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* replaceValueInTree(struct TreeNode* root) {
    if (!root) return root;

    int cap = 100;
    struct TreeNode** bfs = (struct TreeNode**)malloc(cap * sizeof(struct TreeNode*));
    int size = 1;
    bfs[0] = root;

    int prev = root->val;
    struct TreeNode** nextBfs = NULL;
    struct TreeNode* currNode = NULL;
    while (size) {
        int lvl_sz = size;
        int next = 0;
        size = 0;

        nextBfs = (struct TreeNode**)malloc(cap * sizeof(struct TreeNode*));
    
        for (int i = 0; i < lvl_sz; i++) {
            currNode = bfs[i];

            currNode->val = prev - currNode->val;

            int child_sum = (currNode->left ? currNode->left->val : 0) + (currNode->right ? currNode->right->val : 0);

            if (currNode->left) {
                next += currNode->left->val;
                currNode->left->val = child_sum;
                if (size >= cap) {
                    cap *= 2;
                    nextBfs = (struct TreeNode**)realloc(nextBfs, cap * sizeof(struct TreeNode*));
                }
                nextBfs[size++] = currNode->left;
            }

            if (currNode->right) {
                next += currNode->right->val;
                currNode->right->val = child_sum;
                if (size >= cap) {
                    cap *= 2;
                    nextBfs = (struct TreeNode**)realloc(nextBfs, cap * sizeof(struct TreeNode*));
                }
                nextBfs[size++] = currNode->right;
            }
        }

        free(bfs);
        bfs = nextBfs;
        prev = next;
    }
    free(bfs);
    return root;
}