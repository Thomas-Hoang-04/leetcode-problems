class Solution {
    fun lemonadeChange(bills: IntArray): Boolean {
        var fBills : Int = 0;
        var tBills : Int = 0;

        for (b in bills) {
            if (b == 5) fBills++;
            else if (b == 10) {
                if (fBills <= 0) return false;
                fBills--;
                tBills++;
            } else {
                if (fBills > 0 && tBills > 0) {
                    fBills--;
                    tBills--;
                } else if (fBills >= 3) fBills -= 3;
                else return false;
            }
        }

        return true;
    }
}