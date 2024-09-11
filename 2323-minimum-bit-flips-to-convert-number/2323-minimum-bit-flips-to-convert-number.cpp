class Solution {
public:
    int minBitFlips(int start, int goal) {
        start ^= goal;

    goal = 0;
    while (start) {
        goal += (start & 1);
        start >>= 1;
    }

    return goal;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();