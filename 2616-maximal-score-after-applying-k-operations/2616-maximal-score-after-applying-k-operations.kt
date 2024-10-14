class Solution {
    fun maxKelements(nums: IntArray, k: Int): Long {
        var sum: Long = 0
        val pq: PriorityQueue<Int> = PriorityQueue(compareByDescending {it})
        pq.addAll(nums.toList())
        
        var rnd: Int = k;
        while (rnd-- > 0) {
            val ele: Int = pq.poll();
            sum += ele;
            pq.offer(ceil(ele / 3.0).toInt());
        }
        return sum;
    }
}