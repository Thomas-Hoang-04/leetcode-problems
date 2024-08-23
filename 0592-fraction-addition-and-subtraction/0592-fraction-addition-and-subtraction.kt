class Solution {
    private fun findGCD(a: Int, b: Int) : Int {
        if (a == 0) return b;
        return findGCD(b % a, a);
    }
    fun fractionAddition(expr: String): String {
        var n: Int = 0;
        var dn: Int = 1;

        var curr_n: Int; var curr_dn: Int; var neg: Int;

        var i: Int = 0;
        while (i < expr.length) {
            curr_n = 0;
            curr_dn = 0;

            neg = 1;

            if (expr[i] == '-' || expr[i] == '+') {
                if (expr[i] == '-') neg = -1;
                i++;
            }

            while(expr[i].isDigit()) {
                curr_n = curr_n * 10 + (expr[i] - '0');
                i++;
            }

            curr_n *= neg;
            i++;

            while(i < expr.length && expr[i].isDigit()) {
                curr_dn = curr_dn * 10 + (expr[i] - '0');
                i++;
            }

            n = n * curr_dn + curr_n * dn;
            dn *= curr_dn;
        }

        var gcd: Int = abs(findGCD(n, dn));

        n /= gcd;
        dn /= gcd;

        return n.toString() + "/" + dn.toString();
    }
}