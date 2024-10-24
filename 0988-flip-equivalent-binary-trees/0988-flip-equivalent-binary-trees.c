/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct pair {
    struct TreeNode* p1;
    struct TreeNode* p2;
} Pair;


bool checkNodeMatch(struct TreeNode* root1, struct TreeNode* root2) {
    if (!root1 && !root2) return true;
    if (root1 && root2 && root1->val == root2->val) return true;
    return false;
}

bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2) {
    int cap = 100, size = 0;
    Pair** st = (Pair**)malloc(cap * sizeof(Pair*));
    Pair* temp = (Pair*)malloc(sizeof(Pair));
    temp->p1 = root1;
    temp->p2 = root2;
    st[size++] = temp;
    while (size) {
        temp = st[--size];
        if (!temp->p1 && !temp->p2) continue;
        if (!temp->p1 || !temp->p2) return false;
        if (temp->p1->val != temp->p2->val) return false;

        if (checkNodeMatch(temp->p1->left, temp->p2->left) && checkNodeMatch(temp->p1->right, temp->p2->right)) {
            Pair* newPair = (Pair*)malloc(sizeof(Pair));
            newPair->p1 = temp->p1->left;
            newPair->p2 = temp->p2->left;
            st[size++] = newPair;

            newPair = (Pair*)malloc(sizeof(Pair));
            newPair->p1 = temp->p1->right;
            newPair->p2 = temp->p2->right;
            st[size++] = newPair;
        } else if (checkNodeMatch(temp->p1->right, temp->p2->left) && checkNodeMatch(temp->p1->left, temp->p2->right)) {
            Pair* newPair = (Pair*)malloc(sizeof(Pair));
            newPair->p1 = temp->p1->right;
            newPair->p2 = temp->p2->left;
            st[size++] = newPair;

            newPair = (Pair*)malloc(sizeof(Pair));
            newPair->p1 = temp->p1->left;
            newPair->p2 = temp->p2->right;
            st[size++] = newPair;
        } else return false;

        if (size >= cap) {
            cap *= 2;
            st = (Pair**)realloc(st, cap * sizeof(Pair));
        }
    }
    return true;
}