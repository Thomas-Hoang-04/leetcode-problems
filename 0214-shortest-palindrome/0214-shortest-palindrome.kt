class Solution {
    private fun buildPrefTab(s: String): IntArray {
        val prefTab: IntArray = IntArray(s.length) { 0 }
        var len: Int = 0;
        for (i in 1 until s.length) {
            while (len > 0 && s[i] != s[len]) len = prefTab[len - 1];
            if (s[i] == s[len]) len++;
            prefTab[i] = len;
        }
        return prefTab;
    }
    fun shortestPalindrome(s: String): String {
        val comb: String = s + "*" + s.reversed();
        val prefTab: IntArray = buildPrefTab(comb);
        val palLen: Int = prefTab.last();
        val suff: String = s.reversed().substring(0, s.length - palLen);
        return suff + s;
    }
}