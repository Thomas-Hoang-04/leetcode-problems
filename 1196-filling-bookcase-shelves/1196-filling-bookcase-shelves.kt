class Solution {
    fun minHeightShelves(books: Array<IntArray>, shelfWidth: Int): Int {
        val dpHeight = Array<Int>(books.size + 1) { 0 };

        dpHeight[0] = 0;
        dpHeight[1] = books[0][1];

        var remainShelf : Int; 
        var maxH : Int; 
        var t : Int;
        for (h in 2..books.size) {
            t = h - 1;
            remainShelf = shelfWidth - books[t][0];
            maxH = books[t][1];
            dpHeight[h] = dpHeight[t] + maxH;

            while (t > 0 && remainShelf - books[t - 1][0] >= 0) {
                remainShelf -= books[t - 1][0];
                maxH = max(maxH, books[t - 1][1]);
                dpHeight[h] = min(dpHeight[h], dpHeight[t - 1] + maxH);
                t--;
            }
        }

        return dpHeight[books.size];
    }
}