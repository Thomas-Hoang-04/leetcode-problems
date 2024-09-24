class Solution {
    public int findKthNumber(int n, int k) {
        if (k-- == 1)
            return 1;
        int curr = 1;
        long step;

        while (k > 0) {
            step = 0;
            for (long ref = 1, st = curr; st <= n; st *= 10, ref *= 10)
                step += Math.min(n + 1 - st, ref); 
            if (step <= k) {
                curr++;
                k -= step;
            }
            else {
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
}