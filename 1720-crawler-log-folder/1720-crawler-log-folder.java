class Solution {
    public int minOperations(String[] logs) {
        int ops = 0;
        for (String r: logs) {
            if (r.equals("./")) continue;
            if (r.equals("../")) ops = ops > 0 ? ops - 1 : ops;
            else ops++;
        }
        return ops;
    }
}