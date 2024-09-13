/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int* ans = (int*)malloc(queriesSize * sizeof(int));
    int* pref = (int*)malloc(arrSize * sizeof(int));
    pref[0] = arr[0];
    for (int i = 1; i < arrSize; i++) pref[i] = pref[i - 1] ^ arr[i];
    for (int i = 0; i < queriesSize; i++) {
        ans[i] = pref[queries[i][1]];
        if (queries[i][0] > 0) ans[i] ^= pref[queries[i][0] - 1];
    }
    return ans;
}