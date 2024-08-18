class Solution {
    fun nthUglyNumber(n: Int): Int {
        val ugly : IntArray = IntArray(n);
        ugly[0] = 1;

        var idx_2 : Int = 0; var idx_3 : Int = 0; var idx_5 : Int = 0;
        var next_2 : Int = 2; var next_3 : Int = 3; var next_5 : Int = 5;

        for (i in 1..n - 1) {
            var next : Int = min(next_2, min(next_3, next_5));
            ugly[i] = next;

            if (next == next_2) next_2 = ugly[++idx_2] * 2;
            if (next == next_3) next_3 = ugly[++idx_3] * 3; 
            if (next == next_5) next_5 = ugly[++idx_5] * 5;
        }

        return ugly[n - 1];
    }
}