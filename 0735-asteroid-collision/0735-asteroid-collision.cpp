class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int> pow;
        pow.push_back(ast[0]);
        bool track;
        for (int i = 1; i < ast.size(); i++) {
            if (ast[i] > 0 || (!pow.empty() && pow.back() < 0)) pow.push_back(ast[i]);
            else {
                track = true;
                while (!pow.empty() && pow.back() > 0) {
                    if (!track) break;
                    if (ast[i] + pow.back() <= 0) {
                        track = !(ast[i] == -pow.back());
                        pow.pop_back();
                    } else track = false;
                }
                if (track) pow.push_back(ast[i]);
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