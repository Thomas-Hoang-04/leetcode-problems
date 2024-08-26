/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void postOrder_helper(struct Node* root, int* num, int* size) {
    if (!root) return;

    while(root->numChildren--) postOrder_helper(*root->children++, num, size);
    num[(*size)++] = root->val;
}

int* postorder(struct Node* root, int* returnSize) {
    int* num = (int*)malloc(10000 * sizeof(int));
    *returnSize = 0;
    postOrder_helper(root, num, returnSize);
    return num;
}