/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes) {
    if (m * n != originalSize) {
        *returnSize = 0;
        return NULL;
    }
    
    int** ans = (int**)malloc(m * sizeof(int*));
    for (int r = 0; r < m; r++) ans[r] = (int*)malloc(n * sizeof(int));

    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int r = 0; r < m; r++) (*returnColumnSizes)[r] = n;

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            ans[r][c] = original[r * n + c];
        }
    }

    *returnSize = m;

    return ans;
}