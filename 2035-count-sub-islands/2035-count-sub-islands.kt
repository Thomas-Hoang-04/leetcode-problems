class Solution {
    data class Coor(val r: Int, val c: Int);
    private val dirs : Array<Coor> = arrayOf(Coor(0, 1), Coor(1, 0), Coor(0, -1), Coor(-1, 0));
    private lateinit var visited : Array<BooleanArray>;
    private fun isLand(r: Int, c: Int, grid: Array<IntArray>) : Boolean {
        return r >= 0 && c >= 0 && r < grid.size && c < grid[0].size && grid[r][c] == 1;
    }
    private fun isSubIsland(r: Int, c: Int, grid1: Array<IntArray>, grid2: Array<IntArray>) : Int {
        var isSub : Int = 1;

        val pend : Queue<Coor> = LinkedList();
        pend.offer(Coor(r, c));
        visited[r][c] = true;

        var t : Coor;
        var rt: Int; var ct: Int;
        while (!pend.isEmpty()) {
            t = pend.poll();

            if (!isLand(t.r, t.c, grid1)) isSub = 0;

            for (dir in dirs) {
                rt = t.r + dir.r;
                ct = t.c + dir.c;

                if (isLand(rt, ct, grid2) && !visited[rt][ct]) {
                    pend.offer(Coor(rt, ct));
                    visited[rt][ct] = true;
                }
            }
        }

        return isSub;

    }
    fun countSubIslands(grid1: Array<IntArray>, grid2: Array<IntArray>): Int {
        visited = Array(grid1.size) { BooleanArray(grid1[0].size) { false } };
        var subCnt: Int = 0;

        for (r in 0 until grid2.size) 
            for (c in 0 until grid2[0].size) 
                if (!visited[r][c] && isLand(r, c, grid2)) subCnt += isSubIsland(r, c, grid1, grid2);

        return subCnt;
    }
}