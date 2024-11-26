int findChampion(int n, int** edges, int edgesSize, int* edgesColSize) {
    int in_deg[n];
    memset(in_deg, 0, n * sizeof(int));
    for (int i = 0; i < edgesSize; i++) in_deg[edges[i][1]]++;

    int champ, champCnt = 0;
    for (int i = 0; i < n; i++) 
        if (!in_deg[i]) {
            if (champCnt++) return -1;
            champ = i;
        }
    
    return champ;
}