class Solution {
    public boolean judgeSquareSum(int c) {
        long l = 0, r = (long)Math.sqrt((double)c);
        while (l <= r) {
            if (l * l + r * r == c) return true;
            else if (l * l + r * r > c) r--;
            else l++;
        }
        return false;
    }
}