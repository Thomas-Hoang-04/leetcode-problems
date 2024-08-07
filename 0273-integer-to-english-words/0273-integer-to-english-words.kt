class Solution {
    fun numberToWords(num: Int): String {
        if (num == 0) return "Zero";
        val ones = arrayOf<String>("", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen");
        val tens = arrayOf<String>("", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety");
        val thousands = arrayOf<String>("", "Thousand", "Million", "Billion");

        var ref = num;
        var res : String = "";
        var groupIdx : Int = 0;

        while (ref > 0) {
            if (ref % 1000 != 0) {
                var temp : String = "";
                var t : Int = ref % 1000;

                if (t >= 100) {
                    temp += (ones[t / 100] + " Hundred ");
                    t %= 100;
                }

                if (t >= 20) {
                    temp += (tens[t / 10] + " ");
                    t %= 10;
                }
                
                if (t > 0) temp += (ones[t] + " ");

                temp += (thousands[groupIdx] + " ")
                res = temp + res;
            }
            ref /= 1000;
            groupIdx++;
        }

        return res.trim();
    }
}