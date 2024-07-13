class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int> pow;
        bool track;
        for (int s: ast) {
            if (s > 0 || (!pow.empty() && pow.back() < 0)) pow.push_back(s);
            else {
                track = true;
                while (!pow.empty() && pow.back() > 0) {
                    if (!track) break;
                    if (s + pow.back() <= 0) {
                        track = !(s == -pow.back());
                        pow.pop_back();
                    } else track = false;
                }
                if (track) pow.push_back(s);
            }
        }
        return pow;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();