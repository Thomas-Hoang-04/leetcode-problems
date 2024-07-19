class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        int[] track = new int[2];
        track[0] = Integer.MIN_VALUE;
        track[1] = Integer.MAX_VALUE;
        int trace;
        for (int r = 0; r < matrix.length; r++) {
            trace = Integer.MAX_VALUE;
            for (int c = 0; c < matrix[0].length; c++) 
                trace = Math.min(trace, matrix[r][c]);
            track[0] = Math.max(trace, track[0]);
        }
        for (int c = 0; c < matrix[0].length; c++) {
            trace = Integer.MIN_VALUE;
            for (int r = 0; r < matrix.length; r++) 
                trace = Math.max(trace, matrix[r][c]);
            track[1] = Math.min(trace, track[1]); 
        }
        if (track[0] == track[1]) return new ArrayList<>(Arrays.asList(track[0]));
        return new ArrayList<>();
    }
}