class Solution {
    fun canBeEqual(target: IntArray, arr: IntArray): Boolean {
        val mp : Array<Int> = Array(1000) { 0 };
        for (n in target) mp[n - 1]++;
        for (n in arr) mp[n - 1]--;
        for (k in mp) if (k != 0) return false;
        return true;
    }
}