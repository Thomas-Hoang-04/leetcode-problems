class KthLargest(k: Int, nums: IntArray) {
    private val heap : PriorityQueue<Int> = PriorityQueue();
    private var k : Int;
    init {
        this.k = k; 
        for (n in nums) add(n);
    }

    fun add(n: Int): Int {
        if (heap.size < k || heap.peek() < n) {
            heap.add(n);
            if (heap.size > k) heap.poll();
        }
        return heap.peek();
    }

}

/**
 * Your KthLargest object will be instantiated and called as such:
 * var obj = KthLargest(k, nums)
 * var param_1 = obj.add(`val`)
 */