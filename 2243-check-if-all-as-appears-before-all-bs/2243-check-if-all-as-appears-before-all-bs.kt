class Solution {
    fun checkString(s: String): Boolean {
        for (i in 0..s.length - 2) {
            if (s[i] == 'b' && s[i + 1] == 'a') return false;
        }
        return true;
    }
}