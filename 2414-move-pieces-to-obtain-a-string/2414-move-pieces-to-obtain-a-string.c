bool canChange(char* start, char* target) {
    const int tar = strlen(start);
    int stIdx = 0, tarIdx = 0;
    while (stIdx < tar || tarIdx < tar) {
        while (stIdx < tar && start[stIdx] == '_') stIdx++;
        while (tarIdx < tar && target[tarIdx] == '_') tarIdx++;
        
        if (stIdx == tar || tarIdx == tar) {
            return stIdx == tar && tarIdx == tar;
        }

        if (start[stIdx] != target[tarIdx] || 
            (start[stIdx] == 'L' && stIdx < tarIdx) || 
            (start[stIdx] == 'R' && stIdx > tarIdx)
        ) return false;

        stIdx++;
        tarIdx++;
    }
    return true;
}