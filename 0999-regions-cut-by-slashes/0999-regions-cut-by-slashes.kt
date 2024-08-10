class Solution {
    private lateinit var par : IntArray;
    private fun find(node : Int) : Int {
        if (par[node] == -1) return node;

        par[node] = find(par[node]);

        return par[node];
    }
    private fun union(n1 : Int, n2 : Int) : Int {
        val p1 : Int = find(n1);
        val p2 : Int = find(n2);

        if (p1 == p2) return 1;

        par[p2] = p1;
        return 0;
    }
    fun regionsBySlashes(grid: Array<String>): Int {
        val ptsPerE = grid.size + 1;
        par = IntArray(ptsPerE * ptsPerE) { -1 };

        for (r in 0..ptsPerE - 1) 
            for (c in 0..ptsPerE - 1)
                if (r == 0 || c == 0 || r == ptsPerE - 1 || c == ptsPerE - 1) {
                    var p = r * ptsPerE + c;
                    par[p] = 0;
                }

        par[0] = -1;
        var regCnt : Int = 1;
        var top : Int = 0;
        var bottom : Int = 0;

        for (r in 0..grid.size - 1) 
            for (c in 0..grid.size - 1) {
                if (grid[r][c] == '/') {
                    top = r * ptsPerE + c + 1;
                    bottom = (r + 1) * ptsPerE + c;
                    regCnt += union(top, bottom);
                } else if (grid[r][c] == '\\') {
                    top = r * ptsPerE + c;
                    bottom = (r + 1) * ptsPerE + c + 1;
                    regCnt += union(top, bottom);
                }
            }
        
        return regCnt;
    }
}