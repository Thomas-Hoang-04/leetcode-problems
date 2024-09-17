class Solution {
    fun uncommonFromSentences(s1: String, s2: String): Array<String> {
        val s_merge: Array<String> = (s1 + " " + s2).split(" ").toTypedArray();
        val mp: HashMap<String, Int> = hashMapOf();
        val ans: MutableList<String> = mutableListOf();
        for (wrd in s_merge) 
            mp[wrd] = mp.getOrDefault(wrd, 0) + 1;
        for (wrd in mp.keys) 
            if (mp[wrd] == 1) ans.add(wrd);
        return ans.toTypedArray();
    }
}