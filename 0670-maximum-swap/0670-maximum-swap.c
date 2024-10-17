int maximumSwap(int num) {
    if (num < 12) return num;
    int size = (int)(ceil(log10(num))+1) + 1;
    char ans[size];
    sprintf(ans, "%d", num);
    int tar1 = -1, tar2 = -1, maxIdx = -1;
    for (int i = size - 2; i >= 0; i--) {
        if (maxIdx == -1 || ans[i] > ans[maxIdx]) maxIdx = i;
        else if (ans[i] < ans[maxIdx]) {
            tar1 = i;
            tar2 = maxIdx;
        }
    }

    if (tar1 != -1 && tar2 != -1) {
        maxIdx = ans[tar1];
        ans[tar1] = ans[tar2];
        ans[tar2] = maxIdx;
    }

    return atoi(ans);
}