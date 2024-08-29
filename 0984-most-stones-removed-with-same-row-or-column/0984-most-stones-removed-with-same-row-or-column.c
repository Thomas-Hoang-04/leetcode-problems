void dfs(int root, bool* visited, int** graph, int* adjSize) {
    visited[root] = true;

    for (int i = 0; i < adjSize[root]; i++) 
        if (!visited[graph[root][i]]) dfs(graph[root][i], visited, graph, adjSize);
}

int removeStones(int** stones, int stonesSize, int* stonesColSize) {
    bool* visited = (bool*)calloc(stonesSize, sizeof(bool));
    int** graph = (int**)malloc(stonesSize * sizeof(int*));
    for (int i = 0; i < stonesSize; i++) graph[i] = (int*)malloc(1000 * sizeof(int));

    int* adjSize = (int*)calloc(stonesSize, sizeof(int));

    for (int i = 0; i < stonesSize; i++) 
        for (int j = i + 1; j < stonesSize; j++) 
            if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                graph[i][adjSize[i]++] = j;
                graph[j][adjSize[j]++] = i;
            }

    int cnt = 0;
    for (int i = 0; i < stonesSize; i++) 
        if (!visited[i]) {
            cnt++;
            dfs(i, visited, graph, adjSize);
        }

    return stonesSize - cnt;
}