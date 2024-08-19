class Solution {
    fun minSteps(n: Int): Int {
        if (n == 1) return 0;
        var ans : Int = 0;
        var t : Int = n;
        for (f in 2..sqrt(n.toDouble()).toInt()) {
            while (t % f == 0) {
                ans += f;
                t /= f;
            }
        }
        if (t > 1) ans += t;
        return ans;
    }
}