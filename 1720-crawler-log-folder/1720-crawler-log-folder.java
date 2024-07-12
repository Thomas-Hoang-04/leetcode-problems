class Solution {
    private int pos(String log, int ops) {
        return log.charAt(1) == '.' ? ops > 0 ? -1 : 0 : log.charAt(0) == '.' ? 0 : 1;
    }
    public int minOperations(String[] logs) {
        int ops = 0;
        for (String log: logs) ops += pos(log, ops);
        return ops;
    }
}