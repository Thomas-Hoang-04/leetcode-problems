class Solution {
    private int ops;
    private int pos(String log) {
        return log.charAt(1) == '.' ? ops > 0 ? -1 : 0 : log.charAt(0) == '.' ? 0 : 1;
    }
    public int minOperations(String[] logs) {
        ops = 0;
        for (String log: logs) ops += pos(log);
        return ops;
    }
}