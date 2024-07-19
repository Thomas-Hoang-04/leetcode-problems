class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        int[] rows = new int[matrix.length];
        int[] cols = new int[matrix[0].length];
        for (int r = 0; r < matrix.length; r++) 
            for (int c = 0; c < matrix[0].length; c++) {
                rows[r] = rows[r] == 0 ? matrix[r][c] : Math.min(rows[r], matrix[r][c]);
                cols[c] = Math.max(cols[c], matrix[r][c]);
            }
        for (int r = 0; r < matrix.length; r++) 
            for (int c = 0; c < matrix[0].length; c++) 
                if (matrix[r][c] == rows[r] && matrix[r][c] == cols[c]) ans.add(matrix[r][c]);
        return ans;
    }
}