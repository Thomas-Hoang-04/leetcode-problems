class Solution {
    public int maxSatisfied(int[] cust, int[] gr, int min) {
        int win = 0;
        for (int i = 0; i < min; i++) {
            win += cust[i] * gr[i];
        }
        int maxWin = win;
        for (int i = min; i < cust.length; i++) {
            win += cust[i] * gr[i] - cust[i - min] * gr[i - min];
            maxWin = Math.max(win, maxWin);
        }
        for (int i = 0; i < cust.length; i++) maxWin += cust[i] * (1 - gr[i]);
        return maxWin;
    }
}