class Solution {
    fun kthDistinct(arr: Array<String>, k: Int): String {
        val mp : HashMap<String, Int> = HashMap();
        for (str in arr) mp[str] = mp.getOrElse(str) {0} + 1;
        var kVal = k;
        for (s in arr) {
            if (mp.get(s) == 1) kVal--;
            if (kVal == 0) return s;
        }
        return "";
    }
}