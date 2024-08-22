int findComplement(int num) {
    int ans = num;
    long k = 1;
    while (k <= num) {
        ans ^= k;
        k <<= 1;
    }
    return ans;
}