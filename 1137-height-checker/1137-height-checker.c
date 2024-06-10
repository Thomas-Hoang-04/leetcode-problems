int heightChecker(int* heights, int heightsSize) {
    int cnt[101] = {0};
    int* th = heights;

    while (heightsSize--) cnt[*heights++]++;

    int h = 1;
    heightsSize = 0;
    
    while (h < 101) {
        if (!cnt[h]) h++;
        else {
            if (h != *th) heightsSize++;
            th++;
            cnt[h]--;
        }
    }

    return heightsSize;
}