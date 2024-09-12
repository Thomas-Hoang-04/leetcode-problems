class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        Set<Character> storeChar = new HashSet<>();
        for (char c : allowed.toCharArray()) storeChar.add(c);
        int ans = 0;
        boolean stat;
        for (String wrd : words) {
            stat = true;
            for (char c : wrd.toCharArray()) {
                stat = storeChar.contains(c);
                if (!stat) break;
            }

            if (stat) ans++;
        }
        return ans;
    }
}