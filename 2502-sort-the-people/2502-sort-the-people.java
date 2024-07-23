class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        TreeMap<Integer, String> mp = new TreeMap<Integer, String>();
        for (int i = 0; i < heights.length; i++) mp.put(heights[i], names[i]);
        int idx = names.length - 1;
        for (Integer h: mp.keySet()) names[idx--] = mp.get(h);
        return names;
    }
}