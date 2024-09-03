int xorToN(int val) {
    switch (val & 3) {
        case 0: 
            return val;
        case 1:
            return 1;
        case 2: 
            return (val + 1);
        case 3: 
            return 0;
    }
    return 0;
}
int xorOperation(int n, int start) {
    return (start & 1 & n) | ((xorToN((start >> 1) - 1) ^ xorToN((start >> 1) + n - 1)) << 1);
}