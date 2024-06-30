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
    public byte union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return 0;
        if (size[x] > size[y]) {
            size[x] += size[y];
            parent[y] = x;
        } else {
            size[y] += size[x];
            parent[x] = y;
        }
        comp--;
        return 1;
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

        for (int[] e: edges) 
            if (e[0] == 3) minEdges += Alice.union(e[1], e[2]) | Bob.union(e[1], e[2]);
        
        for (int[] e: edges)
            if (e[0] == 1) minEdges += Alice.union(e[1], e[2]);
            else if (e[0] == 2) minEdges += Bob.union(e[1], e[2]);

        if (Alice.isConnected() && Bob.isConnected()) return edges.length - minEdges;
        return -1;
    }
}