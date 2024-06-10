int heightChecker(int* heights, int heightsSize) {
    int cnt[101] = {0};
    int* th = heights;
    int miss = 0;

    while (heightsSize--) cnt[*heights++]++;

    int h = 1;
    while (h < 101) {
        if (!cnt[h]) h++;
        else {
            if (h != *th) miss++;
            th++;
            cnt[h]--;
        }
    }

    return miss;
}