class Solution {
    private List<Integer> ans = new LinkedList<>();
    private void genNums(int curr, int lim) {
        if (curr > lim) return;

        ans.add(curr);

        for (int next = 0; next <= 9; ++next) {
            int nextNum = curr * 10 + next;
            if (nextNum <= lim) genNums(nextNum, lim);
            else break;            
        }
    }
    public List<Integer> lexicalOrder(int n) {
        for (int st = 1; st <= 9; ++st) genNums(st, n);
        return ans;
    }
}