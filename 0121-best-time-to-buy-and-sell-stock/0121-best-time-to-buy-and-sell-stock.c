int maxProfit(int* prices, int pricesSize) {
    int profit = 0, buy = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < prices[buy]) {
           buy = i;
           continue;
        }
        if (profit < prices[i] - prices[buy]) profit = prices[i] - prices[buy];
    }
    return profit;
}