typedef pair<int, int> p2;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<p2> grp(profits.size());
        for (int i = 0; i < profits.size(); i++) grp[i] = {capital[i], profits[i]};
        sort(grp.begin(), grp.end());
        priority_queue<int> pq;
        int curr = 0;
        for (int i = 0; i < k; i++) {
            for (; curr < profits.size() && grp[curr].first <= w; curr++) pq.push(grp[curr].second);

            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            } else break;
        }
        return w;
    }
};