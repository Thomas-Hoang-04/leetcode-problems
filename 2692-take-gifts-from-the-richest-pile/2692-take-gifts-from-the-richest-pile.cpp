class Solution {
public:
    long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        while (k--) {
            int pile = pq.top();
            pq.pop();
            pq.push(sqrt(pile));
        }
        long rem = 0;
        while (!pq.empty()) {
            rem += pq.top();
            pq.pop();
        }
        return rem;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();