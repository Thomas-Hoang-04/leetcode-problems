class Solution {
    public int passThePillow(int n, int time) {  
    int full = time / (n - 1);
    int extra = time % (n - 1);
    if (full % 2 == 1) return n - extra;
    else return extra + 1;
    }
}