from collections import deque
from math import inf

class Solution:
    def secondMinimum (self, n: int, edges: List[List[int]], time: int, change: int) -> int:
        graph = [[] for i in range(n + 1)]
        visited = [[inf, inf] for i in range(n + 1)]
        for start, end in edges:
            graph[start].append(end)
            graph[end].append(start)
        q = deque([(1, 0)]) ; visited[1][0] = 0
        while (q):
            curr_node, curr_time = q.popleft()
            if (curr_node == n):
                if (visited[curr_node][1] != inf): break
            fragment, rem = divmod(curr_time, change)
            next_time = curr_time + time
            if ((fragment % 2) != 0): next_time += (change - rem)
            for next_node in graph[curr_node]:
                if (next_time < visited[next_node][0]):
                    visited[next_node][1] = visited[next_node][0]
                    visited[next_node][0] = next_time
                    q.append((next_node, next_time))
                elif ((next_time > visited[next_node][0]) and (next_time < visited[next_node][1])):
                    visited[next_node][1] = next_time
                    q.append((next_node, next_time))
        return visited[n][1]