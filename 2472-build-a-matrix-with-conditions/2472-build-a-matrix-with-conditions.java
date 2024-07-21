class Solution {
    private int[] topo(int[][] edges, int n) {
        List<Integer>[] adj = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) adj[i] = new ArrayList<Integer>();

        int[] in_deg = new int[n + 1], vert = new int[n];

        for (int[] e: edges) {
            adj[e[0]].add(e[1]);
            in_deg[e[1]]++;
        }

        int idx = 0, t;
        Queue<Integer> q = new LinkedList<>();

        for (int i = 1; i <= n; i++) if (in_deg[i] == 0) q.offer(i);

        while (!q.isEmpty()) {
            t = q.poll();
            vert[idx++] = t;
            n--;
            for (int v: adj[t]) if (--in_deg[v] == 0) q.offer(v);
        }

        if (n != 0) return new int[0];

        return vert;
    }
    public int[][] buildMatrix(int k, int[][] rowConditions, int[][] colConditions) {
        int[] row = topo(rowConditions, k);
        int[] col = topo(colConditions, k);

        if (row.length == 0 || col.length == 0) return new int[0][0];

        int[][] ans = new int[k][k];
        for (int r = 0; r < k; r++) 
            for (int c = 0; c < k; c++) 
                if (row[r] == col[c]) ans[r][c] = row[r];

        return ans;
    }
}