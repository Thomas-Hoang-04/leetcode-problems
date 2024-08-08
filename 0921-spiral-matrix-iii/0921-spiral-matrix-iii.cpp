#pragma GCC optimize(O3, "unroll-loops")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> trav;

        for (int step = 1, direct = 0; trav.size() < rows * cols;) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < step; j++) {
                    if (rStart >= 0 && rStart < rows && cStart >= 0 &&
                        cStart < cols) {
                        trav.push_back({rStart, cStart});
                    }
                    rStart += dir[direct][0];
                    cStart += dir[direct][1];
                }
                direct = (direct + 1) % 4;
            }
            ++step;
        }
        return trav;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();