int minFlips(int a, int b, int c){
    if ((a | b) == c) return 0;

    int count = 0;
    c ^= (a | b);
    a &= b;
    
    while (c) {
        count += (c & 1) + (a & 1 & c);
        a >>= 1;
        c >>= 1;
    }   

    return count;
}