class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        String[] wrds = new StringBuilder(s1 + " " + s2).toString().split(" ");
        HashMap<String, Integer> mp = new HashMap<>();
        for (String wrd: wrds) mp.put(wrd, mp.getOrDefault(wrd, 0) + 1);
        List<String> ans = new LinkedList<>();
        for (String wrd: mp.keySet()) 
            if (mp.get(wrd) == 1) ans.add(wrd);

        return ans.toArray(new String[ans.size()]);
    }
}