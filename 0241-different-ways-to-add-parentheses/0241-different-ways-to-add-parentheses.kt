class Solution {
    fun diffWaysToCompute(expr: String): List<Int> {
        if (expr.length == 0) return emptyList();

        if (expr.length == 1 || (expr.length == 2 && expr[0].isDigit())) return listOf(expr.toInt());

        val res: MutableList<Int> = mutableListOf();

        var ch: Char; var compRes: Int;
        for (i in 0 until expr.length) {
            ch = expr[i];

            if (ch.isDigit()) continue;

            val left: List<Int> = diffWaysToCompute(expr.substring(0, i));
            val right: List<Int> = diffWaysToCompute(expr.substring(i + 1));
            
            for (leftval in left) 
                for (rightval in right) {
                    compRes = 0;

                    when (ch) {
                        '+' -> compRes = leftval + rightval; 
                        '-' -> compRes = leftval - rightval; 
                        '*' -> compRes = leftval * rightval; 
                    }

                    res.add(compRes);
                }
        }

        return res;
    }
}