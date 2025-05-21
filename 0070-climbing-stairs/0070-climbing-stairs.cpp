class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int st = 1, e = 2, ans;
        for (int i = 2; i < n; i++) {
            ans = st + e;
            st = e;
            e = ans;
        }
        return ans;
    }
};