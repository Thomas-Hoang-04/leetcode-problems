class Solution {
    public double averageWaitingTime(int[][] customers) {
        int curr_time = customers[0][0];
        double wait_time = 0;
        for (int[] time: customers) {
            if (curr_time < time[0]) {
                wait_time += time[1];
                curr_time = time[0] + time[1];
            }
            else {
                curr_time += time[1];
                wait_time += curr_time - time[0];
            }
            System.out.println(wait_time);
        }   
        return wait_time / customers.length;
    }
}