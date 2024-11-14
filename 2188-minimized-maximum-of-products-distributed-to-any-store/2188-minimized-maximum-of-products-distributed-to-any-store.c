bool canDistribute(int x, int* quant, int quantSize, int n) {
    int idx = 0;
    int rem = quant[idx];

    for (;n;n--) {
        if (rem <= x) {
            idx++;
            if (idx == quantSize) return true;
            else rem = quant[idx];
        } else rem -= x;
    }

    return false;
}

int minimizedMaximum(int n, int* quantities, int quantitiesSize) {
    int st = 0;
    int e = INT_MIN;
    for (int i = 0; i < quantitiesSize; i++) e = e > quantities[i] ? e : quantities[i];

    int mid;
    while (st < e) {
        mid = st + (e - st) / 2;
        if (canDistribute(mid, quantities, quantitiesSize, n)) e = mid;
        else st = mid + 1;
    }
    return st;
}