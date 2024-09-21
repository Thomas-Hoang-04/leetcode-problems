class Solution {
    fun lexicalOrder(n: Int): List<Int> {
        val ans: MutableList<Int> = mutableListOf();
        var curr: Int = 1;

        repeat(n) {
            ans.add(curr);

            if (curr * 10 <= n) curr *= 10;
            else {
                while (curr % 10 == 9 || curr >= n) curr /= 10;
                curr++;
            }
        }

        return ans;
    }
}