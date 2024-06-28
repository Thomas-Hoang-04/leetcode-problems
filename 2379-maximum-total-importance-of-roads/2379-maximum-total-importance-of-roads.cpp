typedef pair<int, int> p2;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> level(n, 0);
        for (int i = 0; i < roads.size(); i++) 
            for (int j = 0; j < 2; j++) level[roads[i][j]]++;
        priority_queue<p2> pq;
        for (int i = 0; i < n; i++) pq.push({ level[i], i });
        p2 t;
        while (!pq.empty()) {
            t = pq.top();
            pq.pop();
            level[t.second] = n--;
        }
        long long sumIpt = 0;
        for (int i = 0; i < roads.size(); i++) sumIpt += level[roads[i][0]] + level[roads[i][1]];
        return sumIpt;
    }
};