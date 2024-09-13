/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int* ans = (int*)malloc(queriesSize * sizeof(int));
    for (int i = 1; i < arrSize; i++) arr[i] ^= arr[i - 1];
    for (int i = 0; i < queriesSize; i++) {
        ans[i] = arr[queries[i][1]];
        if (queries[i][0] > 0) ans[i] ^= arr[queries[i][0] - 1];
    }
    return ans;
}