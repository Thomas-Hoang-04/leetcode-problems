class Solution {
    fun longestCommonPrefix(arr1: IntArray, arr2: IntArray): Int {
        val pref: HashSet<Int> = HashSet();
        var t: Int;
        for (v in arr1) {
            t = v;
            while (!pref.contains(t) && t > 0) {
                pref.add(t);
                t /= 10;
            }
        }

        var maxPref: Int = 0;

        for (v in arr2) {
            t = v;
            while (!pref.contains(t) && t > 0) t /= 10;
            if (t > 0) maxPref = max(maxPref, (log10(t.toFloat()) + 1).toInt());
        }

        return maxPref;
    }
}