class Solution {
    fun countConsistentStrings(allowed: String, words: Array<String>): Int {
        val mp: BooleanArray = BooleanArray(26) { false }.apply {
            for (c in allowed) set(c - 'a', true);
        }
        var ans: Int = 0; var stat: Boolean;
        for (str in words) {
            stat = true;
            for (c in str) 
                if (!mp[c - 'a']) {
                    stat = false;
                    break;
                }

                if (stat) ans++;
        }
        return ans; 
    }
}