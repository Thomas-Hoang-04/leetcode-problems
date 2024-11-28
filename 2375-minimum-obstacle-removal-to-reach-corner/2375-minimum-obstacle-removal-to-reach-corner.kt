class Solution {
    data class Tag(val obs: Int, val r: Int, val c: Int)
    private val dirs: Array<IntArray> = arrayOf(
        intArrayOf(0, 1),
        intArrayOf(0, -1),
        intArrayOf(1, 0),
        intArrayOf(-1, 0),
    )
    private fun isValid(grid: Array<IntArray>, r: Int, c: Int): Boolean 
        = r >= 0 && c >= 0 && r < grid.size && c < grid[0].size
    fun minimumObstacles(grid: Array<IntArray>): Int {
        val rSize: Int = grid.size
        val cSize: Int = grid[0].size

        val minObs: Array<IntArray> = Array(rSize) { 
            IntArray(cSize) { Int.MAX_VALUE }
        }.apply { this[0][0] = 0 }

        val q: ArrayDeque<Tag> = ArrayDeque(listOf(Tag(0, 0, 0)))

        while (!q.isEmpty()) {
            val curr: Tag = q.removeFirst()

            for (dir in dirs) {
                val newR: Int = curr.r + dir[0]
                val newC: Int = curr.c + dir[1]

                if (isValid(grid, newR, newC) && minObs[newR][newC] == Int.MAX_VALUE) {
                    if (grid[newR][newC] == 1) {
                        minObs[newR][newC] = curr.obs + 1;
                        q.addLast(Tag(curr.obs + 1, newR, newC))
                    } else {
                        minObs[newR][newC] = curr.obs;
                        q.addFirst(Tag(curr.obs, newR, newC))
                    }
                }
            }
        }

        return minObs.last().last();
    }
}