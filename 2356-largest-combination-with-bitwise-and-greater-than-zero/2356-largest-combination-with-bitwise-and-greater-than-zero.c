int largestCombination(int* cand, int candidatesSize) {
    int cnt, maxCnt = 0;
    for (int i = 0; i < 24; i++) {
        cnt = 0;
        for (int j = 0; j < candidatesSize; j++) 
            if ((cand[j] >> i) & 1) cnt++;
        maxCnt = cnt > maxCnt ? cnt : maxCnt;        
    }
    return maxCnt;
}