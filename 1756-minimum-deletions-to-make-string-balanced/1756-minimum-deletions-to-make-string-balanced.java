class Solution {
    public int minimumDeletions(String s) {
        int min_del = 0;
        int b_cnt = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'b') b_cnt++;
            else min_del = Math.min(min_del + 1, b_cnt);
        }

        return min_del;
    }
}