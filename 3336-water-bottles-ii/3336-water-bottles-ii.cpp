class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles, total = numBottles;
        while (numExchange <= total) {
            total -= numExchange++ - 1;
            ans++;
        } 
        return ans;
    }
};