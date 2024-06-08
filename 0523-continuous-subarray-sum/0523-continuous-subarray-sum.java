class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int preMod = 0;
        HashMap<Integer, Integer> modTrack = new HashMap<Integer, Integer>();
        modTrack.put(0, -1);

        for (int i = 0 ; i < nums.length; i++) {
            if (i > 0 && nums[i] == 0 && nums[i - 1] == 0) return true;
            preMod = (preMod + nums[i]) % k;

            if (modTrack.get(preMod) != null) {
                if (i - modTrack.get(preMod) > 1) return true;
            }
            else modTrack.put(preMod, i);
        }

        return false;
    }
}