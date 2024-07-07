class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0, extra = 0;
        while (numBottles) {
            ans += numBottles;
            numBottles += extra;
            extra = numBottles % numExchange;
            numBottles /= numExchange;
        }
        return ans;
    }
};