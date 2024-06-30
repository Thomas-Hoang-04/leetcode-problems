class UnionFind {
    private int[] parent, size;
    private int comp;
    public UnionFind(int n) {
        parent = IntStream.range(0, n + 1).toArray();
        size = new int[n + 1];
        Arrays.fill(size, 1);
        comp = n;
    }   
    private int find(int tar) {
        if (tar == parent[tar]) return tar;
        return parent[tar] = find(parent[tar]);
    }
    public boolean union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (size[x] > size[y]) {
            size[x] += size[y];
            parent[y] = x;
        } else {
            size[y] += size[x];
            parent[x] = y;
        }
        comp--;
        return true;
    }
    public boolean isConnected() {
        return comp == 1;
    }
}

class Solution {
    public int maxNumEdgesToRemove(int n, int[][] edges) {
        UnionFind Alice = new UnionFind(n);
        UnionFind Bob = new UnionFind(n);
        
        int minEdges = 0;

        for (int i = 0; i < edges.length; i++) 
            if (edges[i][0] == 3) minEdges += Boolean.compare(Alice.union(edges[i][1], edges[i][2]) | Bob.union(edges[i][1], edges[i][2]), false);
        
        for (int i = 0; i < edges.length; i++) 
            if (edges[i][0] == 1) minEdges += Boolean.compare(Alice.union(edges[i][1], edges[i][2]), false);
            else if (edges[i][0] == 2) minEdges += Boolean.compare(Bob.union(edges[i][1], edges[i][2]), false);

        if (Alice.isConnected() && Bob.isConnected()) return edges.length - minEdges;
        return -1;
    }
}