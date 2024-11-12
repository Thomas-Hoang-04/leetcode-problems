/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp1(const void* a, const void* b) {
    int** x = (int**)a;
    int** y = (int**)b;
    return **x - **y;
}

int* maximumBeauty(int** items, int itemsSize, int* itemsColSize, int* queries, int queriesSize, int* returnSize) {
    int* ans = (int*)malloc(queriesSize * sizeof(int));
    qsort(items, itemsSize, 2 * sizeof(int), cmp1);

    int** idxQuery = (int**)malloc(queriesSize * sizeof(int*));
    for (int i = 0; i < queriesSize; i++) idxQuery[i] = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < queriesSize; i++) {
        idxQuery[i][0] = queries[i];
        idxQuery[i][1] = i;
    }

    qsort(idxQuery, queriesSize, 2 * sizeof(int), cmp1);

    int itemIdx = 0;
    int maxBeauty = 0;

    int q, idx;
    for (int i = 0; i < queriesSize; i++) {
        q = idxQuery[i][0];
        idx = idxQuery[i][1];

        while (itemIdx < itemsSize && items[itemIdx][0] <= q) {
            maxBeauty = maxBeauty > items[itemIdx][1] ? maxBeauty : items[itemIdx][1];
            itemIdx++;
        }

        ans[idx] = maxBeauty;
    }

    *returnSize = queriesSize;
    return ans;
}