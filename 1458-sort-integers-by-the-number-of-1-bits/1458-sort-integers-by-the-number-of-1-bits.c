/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int bit_set[256] = { 0 };

int countSetBits(int n) {
    return (bit_set[n & 0xff] + bit_set[(n >> 8) & 0xff] + bit_set[(n >> 16) & 0xff] + bit_set[(n >> 24)]);
}

int cmp(const void* x, const void* y) {
    int* a = (int*)x;
    int* b = (int*)y;
    int count = countSetBits(*a) - countSetBits(*b);
    return count == 0 ? *a - *b : count;
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    for (int i = 0; i < 256; i++) bit_set[i] = (i & 1) + bit_set[i / 2];
    qsort(arr, arrSize, sizeof(int), cmp);
    *returnSize = arrSize;
    return arr;
}