/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* lexicalOrder(int n, int* returnSize) {
    *returnSize = n;
    int* ans = (int*)malloc(n * sizeof(int));
    int curr = 1;

    for (int i = 0; i < n; i++) {
        ans[i] = curr;

        if (curr * 10 <= n) curr *= 10;
        else {
            while (curr % 10 == 9 || curr >= n) curr /= 10;
            curr++;
        }
    }

    return ans;
}