class Solution {
    private static boolean track;
    public int[] asteroidCollision(int[] ast) {
        int[] pow = new int[ast.length];
        int curr_pow = 0;
        for (int s: ast) {
            if (s > 0 || (curr_pow > 0 && pow[curr_pow - 1] < 0)) pow[curr_pow++] = s;
            else {
                track = true;
                while (curr_pow > 0 && pow[curr_pow - 1] > 0) {
                    if (!track) break;
                    if (s + pow[curr_pow - 1] <= 0) {
                        track = !(s == -pow[curr_pow-- - 1]);
                    } else track = false;
                }
                if (track) pow[curr_pow++] = s;
            }
        }
        return Arrays.copyOf(pow, curr_pow);
    }
}