class Solution {
    fun minimumPushes(word: String): Int {
        val letterCnt = IntArray(26);
        var maxKey : Int = 8;
        var push : Int = 1;
        var ans = 0;
        for (c in word) letterCnt[c - 'a']++;
        letterCnt.sortDescending();
        for (c in letterCnt) {
            if (c == 0) break;
            ans += push * c;
            maxKey--;
            if (maxKey == 0) {
                push++;
                maxKey = 8;
            }
        }
        return ans;
    }
}