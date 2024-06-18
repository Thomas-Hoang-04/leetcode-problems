class Solution {
    public int maxProfitAssignment(int[] diff, int[] profit, int[] worker) {
        int maxStre = Arrays.stream(worker).max().getAsInt();
        int[] jobsMaxProf = new int[maxStre + 1];

        for (int i = 0; i < diff.length; i++) if (diff[i] <= maxStre) jobsMaxProf[diff[i]] = Math.max(jobsMaxProf[diff[i]], profit[i]);

        for (int i = 1; i < maxStre + 1; i++) jobsMaxProf[i] = Math.max(jobsMaxProf[i], jobsMaxProf[i - 1]);

        int maxProfit = 0;
        for (int abl: worker) maxProfit += jobsMaxProf[abl];
        return maxProfit;
    }
}