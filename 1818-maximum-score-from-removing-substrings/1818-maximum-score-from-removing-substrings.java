class Solution {
    private int pairs;
    private StringBuilder carb;
    private int clear(String match, int pts) {
        int total_pts = 0;
        int w_idx = 0;

        for (int r_idx = 0; r_idx < carb.length(); r_idx++) {
            carb.setCharAt(w_idx++, carb.charAt(r_idx));

            if (w_idx < 2) continue;
            if (carb.charAt(w_idx - 2) == match.charAt(0) && carb.charAt(w_idx - 1) == match.charAt(1)) {
                w_idx -= 2;
                total_pts += pts;
            } 
        }
        
        carb.setLength(w_idx);

        return total_pts;
    }
    public int maximumGain(String s, int x, int y) {
        pairs = 0;
        carb = new StringBuilder(s);

        if (x > y) {
            pairs += clear("ab", x);
            pairs += clear("ba", y);
        } else {
            pairs += clear("ba", y);
            pairs += clear("ab", x);
        }

        return pairs;
    }
}