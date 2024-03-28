bool isPalindrome(int x) {
    if (x < 0) return false;
    else if (x < 10) return true;
    else {
        int m, t = x;
        long int res = 0;
        while (t) {
            m = t % 10;
            res = 10 * res + m;
            t = t / 10; 
        }
        return res == x;
    }
}