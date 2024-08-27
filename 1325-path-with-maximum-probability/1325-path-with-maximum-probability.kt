class Solution {
    data class Edge(val v: Int, val p: Double);

    fun maxProbability(n: Int, edges: Array<IntArray>, succProb: DoubleArray, st: Int, e: Int): Double {
        val graph : Array<MutableList<Edge>> = Array(n) { mutableListOf<Edge>() }.apply {
            edges.forEachIndexed { i, (u, v) -> 
                get(u).add(Edge(v, succProb[i]));
                get(v).add(Edge(u, succProb[i]));
            }
        };

        val maxProb : DoubleArray = DoubleArray(n) { 0.0 }.apply { set(st, 1.0) };

        val pq : PriorityQueue<Edge> = PriorityQueue<Edge>(compareByDescending { it.p }).apply { offer(Edge(st, 1.0)) };

        while (!pq.isEmpty()) {
            val next = pq.poll();

            if (next.v == e) return next.p;

            for (pr in graph[next.v]) {
                if (next.p * pr.p > maxProb[pr.v]) {
                    maxProb[pr.v] = next.p * pr.p;
                    pq.offer(Edge(pr.v, maxProb[pr.v]));
                }
            }
        }

        return 0.0;
    }
}