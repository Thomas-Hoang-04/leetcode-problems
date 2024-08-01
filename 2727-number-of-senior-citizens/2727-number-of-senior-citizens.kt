class Solution {
    fun countSeniors(details: Array<String>): Int {
        var cnt : Int = 0;
        var ageT : Int;
        var age : Int;
        for (id in details) {
            ageT = id[11] - '0';
            age = id[12] - '0';

            if (ageT * 10 + age > 60) cnt++;
        }

        return cnt;
    }
}