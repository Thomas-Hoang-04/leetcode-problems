class Solution {
    fun maxProbability(n: Int, edges: Array<IntArray>, succProb: DoubleArray, st: Int, e: Int): Double {
        val graph : Array<MutableList<Pair<Double, Int>>> = Array(n) { mutableListOf() };

        for (i in 0 until edges.size) {
            graph[edges[i][0]].add(Pair(succProb[i], edges[i][1]));
            graph[edges[i][1]].add(Pair(succProb[i], edges[i][0]));
        }

        val maxProb : DoubleArray = DoubleArray(n) { 0.0 };
        maxProb[st] = 1.0;

        val pq : PriorityQueue<Pair<Double, Int>> = PriorityQueue(compareBy { it.first });
        pq.offer(Pair(-1.0, st));

        while (!pq.isEmpty()) {
            val (p, v) = pq.poll();

            if (v == e) return -p;

            for (pr in graph[v]) {
                if (-p * pr.first > maxProb[pr.second]) {
                    maxProb[pr.second] = -p * pr.first;
                    pq.offer(Pair(-maxProb[pr.second], pr.second));
                }
            }
        }

        return 0.0;
    }
}