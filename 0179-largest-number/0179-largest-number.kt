class Solution {
    fun largestNumber(nums: IntArray): String {
        val str_nums: Array<String> = nums.map { n -> n.toString() }.toTypedArray();
        val concatComp : Comparator<String> = Comparator<String> { s1, s2 -> (s2 + s1).compareTo(s1 + s2) };
        str_nums.sortWith(concatComp);
        if (str_nums[0] == "0") return "0";
        var ans: String = "";
        for (n in str_nums) ans += n;
        return ans;
    }
}