class Solution {
    public int lengthOfLongestSubstring(String s) {
       boolean[] map = new boolean[128];
       int l = 0, maxL = 0;

       for (int r = 0; r < s.length(); r++) {
        while (map[s.charAt(r)]) {
            map[s.charAt(l)] = false;
            l++;
        }
        map[s.charAt(r)] = true;;
        maxL = Math.max(maxL, r -l + 1);
       }
       return maxL;
    }
}