class Solution {
public:
    int minFlips(int a, int b, int c) {
        if ((a | b) == c) return 0;

        c ^= (a | b);
        a &= b;
        b = 0;

        while (c) {
            b += (c & 1) + (a & 1 & c);
            a >>= 1;
            c >>= 1;
        }

        return b;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();