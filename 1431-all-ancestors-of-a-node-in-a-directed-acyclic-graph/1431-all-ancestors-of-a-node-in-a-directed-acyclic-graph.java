class Solution {
    private List<Integer>[] g;
    private List<List<Integer>> p;
    private void findParDFS(int prev, int curr) {
        for (int adj: g[curr]) {
            if (p.get(adj).isEmpty() || p.get(adj).lastIndexOf(prev) != p.get(adj).size() - 1) {
                p.get(adj).add(prev);
                findParDFS(prev, adj);
            }
        }
    }
    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        g = new ArrayList[n];
        p = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
            p.add(new ArrayList<>());
        }

        for (int i = 0; i < edges.length; i++) g[edges[i][0]].add(edges[i][1]);
        for (int i = 0; i < n; i++) findParDFS(i, i);

        return p;
    }
}