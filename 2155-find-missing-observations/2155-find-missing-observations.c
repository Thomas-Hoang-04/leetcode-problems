/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* missingRolls(int* rolls, int rollsSize, int mean, int n, int* returnSize) {
    int sum = 0;
    for (int i = 0; i < rollsSize; i++) sum += rolls[i];
    sum = (rollsSize + n) * mean - sum;
    if (sum > n * 6 || sum < n) {
        *returnSize = 0;
        return NULL;
    }
    int mod = sum % n, dice = sum / n;
    *returnSize = n;
    int* ans = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (i < mod) ans[i] = dice + 1;
        else ans[i] = dice;
    }
    return ans;
}