class Solution {
    public int heightChecker(int[] heights) {
        int[] cnt = new int[101];
        int miss = 0;

        for (int h: heights) cnt[h]++;

        int h = 1, idx = 0;
        while (h < 101) {
            if (cnt[h] == 0) h++;
            else {
                if (h != heights[idx]) miss++;
                idx++;
                cnt[h]--;
            }            
        }

        return miss;
    }
}