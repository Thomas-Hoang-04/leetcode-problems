class Solution {
    fun maxDistance(arrays: List<List<Int>>): Int {
        var minEle : Int = 1e5.toInt();
        var maxEle : Int = (-1e5).toInt();
        var diff : Int = 0;

        for (arr in arrays) {
            diff = max(diff, max(arr.last() - minEle, maxEle - arr[0]));
            minEle = min(minEle, arr[0]);
            maxEle = max(maxEle, arr.last());
        }

        return diff;
    }
}