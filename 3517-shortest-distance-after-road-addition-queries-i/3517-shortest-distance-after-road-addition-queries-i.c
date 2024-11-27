/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int bfs(int n, int** graph, int child_size[n]) {
    bool visited[n];
    memset(visited, false, n * sizeof(bool));
    int q[n];
    int curr = 0, size = 0;
    q[size++] = 0;
    visited[0] = true;

    int currLayer = 1;
    int nextLayer = 0;
    int layerCnt = 0;

    int temp, t_size, nei;
    while (curr != size) {
        for (int i = 0; i < currLayer; i++) {
            temp = q[curr++];

            if (temp == n - 1) return layerCnt;

            int t_size = child_size[temp];
            for (int i = 0; i < t_size; i++) {
                int nei = graph[temp][i];
                if (visited[nei]) continue;
                q[size++] = nei;
                nextLayer++;
                visited[nei] = true;
            }
        }

        currLayer = nextLayer;
        nextLayer = 0;
        layerCnt++;
    }

    return -1;
}

int* shortestDistanceAfterQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int* ans = (int*)malloc(queriesSize * sizeof(int));
    int ans_size = 0;
    int** graph = (int**)malloc(n * sizeof(int*));
    int child_size[n];
    memset(child_size, 0, n * sizeof(int));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        if (i == n - 1) continue;
        graph[i][child_size[i]++] = i + 1;
    }
    
    for (int i = 0; i < queriesSize; i++) {
        int u = queries[i][0];
        int v = queries[i][1];
        graph[u][child_size[u]++] = v;
        ans[ans_size++] = bfs(n, graph, child_size);
    }

    return ans;
}