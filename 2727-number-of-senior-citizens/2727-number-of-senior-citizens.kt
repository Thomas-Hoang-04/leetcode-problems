class Solution {
    fun countSeniors(details: Array<String>): Int {
        return details.count {
            id -> id[11] > '6' || (id[11] == '6' && id[12] > '0');
        }
    }
}