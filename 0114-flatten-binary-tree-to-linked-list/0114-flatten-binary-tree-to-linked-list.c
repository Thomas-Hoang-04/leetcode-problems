/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void preOrder(struct TreeNode* root, struct TreeNode* prev) {
    if (root == NULL)
        return;
    preOrder(root->left, root);
    if (prev != NULL) {
        if (root->left == NULL && root->right == NULL) {
            root->right = prev->right;
            prev->right = root;
            prev->left = NULL;
        } else {
            struct TreeNode* t = root;
            do {
                t = t->right;
            } while (t->right != NULL);
            t->right = prev->right;
            prev->right = root;
            prev->left = NULL;
        }
    } else {
        preOrder(root->right, prev);
    }
}

void flatten(struct TreeNode* root) {
    preOrder(root, NULL);
}