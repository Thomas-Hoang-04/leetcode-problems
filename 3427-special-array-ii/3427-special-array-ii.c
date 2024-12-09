/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* isArraySpecial(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    bool* ans = (bool*)malloc(queriesSize * sizeof(bool));
    int prefix[numsSize];
    prefix[0] = 0;
    for (int i = 1; i < numsSize; i++) {
        if ((nums[i] & 1) ^ (nums[i - 1] & 1)) prefix[i] = prefix[i - 1];
        else prefix[i] = prefix[i - 1] + 1;
    }

    int st, e;
    for (int i = 0; i < queriesSize; i++) {
        st = queries[i][0];
        e = queries[i][1];

        ans[i] = prefix[e] - prefix[st] == 0;
    }

    return ans;
}