class Solution {
    private int[][] dist;
    private void floydWarshall(int n) {
        for (int v = 0; v < n; v++) 
            for (int i = 0; i < n; i++) 
                for (int j = 0; j < n; j++) 
                    dist[i][j] = Math.min(dist[i][j], dist[i][v] + dist[v][j]);
    } 
    private int findCityMinNeighbor(int n, int thres) {
        int ans = -1, ref = n;
        int cnt;
        for (int st = 0; st < n; st++) {
            cnt = 0;
            for (int e = 0; e < n; e++) {
                if (st == e) continue;
                if (dist[st][e] <= thres) cnt++;
            }
            if (cnt <= ref) {
                ref = cnt;
                ans = st;
            }
        }
        return ans;
    }
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        dist = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dist[i], (int)1e5);
            dist[i][i] = 0;
        }
        for (int[] e: edges) {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        floydWarshall(n);

        return findCityMinNeighbor(n, distanceThreshold);
    }
}