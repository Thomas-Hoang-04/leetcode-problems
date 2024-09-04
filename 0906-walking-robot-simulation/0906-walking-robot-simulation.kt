class Solution {
    data class Coor(val x: Int, val y: Int);
    enum class Direction(val crd: Coor)  {
        NORTH(Coor(0, 1)),
        EAST(Coor(1, 0)),
        SOUTH(Coor(0, -1)),
        WEST(Coor(-1, 0));

        fun rtRight(): Direction {
        return when (this) {
            NORTH -> EAST
            EAST -> SOUTH
            SOUTH -> WEST
            WEST -> NORTH
        }
    }

        fun rtLeft(): Direction {
            return when (this) {
                NORTH -> WEST
                WEST -> SOUTH
                SOUTH -> EAST
                EAST -> NORTH
            }
        }
    }
    private fun euclidDist(crd: Coor): Int {
        return crd.x * crd.x + crd.y * crd.y;
    }
    fun robotSim(commands: IntArray, obstacles: Array<IntArray>): Int {
        var obst : Array<Coor> = obstacles.map { Coor(it[0], it[1]) }.toTypedArray();
        var currPos : Coor = Coor(0, 0);
        var maxDist : Int = 0; var currDir : Direction = Direction.NORTH;
        var nextX: Int; var nextY: Int;

        for (cmd in commands) {
            if (cmd == -1) {
                currDir = currDir.rtRight();
                continue;
            }
            if (cmd == -2) {
                currDir = currDir.rtLeft();
                continue;
            }

            for (st in 1..cmd) {
                var nextX = currPos.x + currDir.crd.x;
                var nextY = currPos.y + currDir.crd.y;
                if (obst.filter { it == Coor(nextX, nextY) }.size > 0) break;
                currPos = Coor(nextX, nextY);
            }

            maxDist = max(maxDist, euclidDist(currPos));
        }

        return maxDist;
    }
}