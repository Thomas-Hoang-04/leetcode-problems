class Solution {
    data class Edge(val v: Int, val w: Int);
    private lateinit var graph : Array<MutableList<Edge>>;
    private val maxWeig : Int = (1e9 + 1).toInt();
    private fun dijkstra(n: Int, src: Int, dest: Int) : Int {
        val minDist : IntArray = IntArray(n) { maxWeig }.apply { set(src, 0) };
        val pq : PriorityQueue<Edge> = PriorityQueue<Edge>(compareBy { it.w }).apply { offer(Edge(src, 0)) };

        while (!pq.isEmpty()) {
            val e : Edge = pq.poll();

            if (e.w > minDist[e.v]) continue;

            for (ed in graph[e.v]) {
                if (ed.w + e.w < minDist[ed.v]) {
                    minDist[ed.v] = ed.w + e.w;
                    pq.offer(Edge(ed.v, minDist[ed.v]));
                }
            }
        }

        return minDist[dest];
    }
    fun modifiedGraphEdges(n: Int, edges: Array<IntArray>, src: Int, dest: Int, tar: Int): Array<IntArray> {
        graph = Array(n) { mutableListOf<Edge>() };

        for (edge in edges) {
            if (edge[2] == -1) continue;

            graph[edge[0]].add(Edge(edge[1], edge[2]));
            graph[edge[1]].add(Edge(edge[0], edge[2]));
        }

        var currMin : Int = dijkstra(n, src, dest);

        if (currMin < tar) return emptyArray();

        var match : Boolean = currMin == tar;

        for (edge in edges) {
            if (edge[2] != -1) continue;

            edge[2] = if (match) maxWeig else 1;
            graph[edge[0]].add(Edge(edge[1], edge[2]));
            graph[edge[1]].add(Edge(edge[0], edge[2]));

            if (!match) {
                currMin = dijkstra(n, src, dest);

                if (currMin <= tar) {
                    match = true;
                    edge[2] += tar - currMin;
                }
            }
        }

        return if (match) edges else emptyArray();
    }
}