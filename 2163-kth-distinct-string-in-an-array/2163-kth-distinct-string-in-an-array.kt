class Solution {
    fun kthDistinct(arr: Array<String>, k: Int): String {
        val mp = LinkedHashMap<String, Int>();
        for (str in arr) mp[str] = mp.getOrDefault(str, 0) + 1;
        val resMp = mp.filter { (k, v) -> v == 1 };

        var i = 1;
        for (key in resMp.keys) if (i++ == k) return key;
        return "";
    }
}