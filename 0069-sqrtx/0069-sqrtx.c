int mySqrt(int x) {
    if (x == 0 || x == 1) return x;
    
    // Use binary search to narrow the square root
    int start = 1, end = x, mid = -1;
    long int square;
    while (start <= end) {
        mid = start + (end - start) / 2;

        square = (long int)mid * mid;

        if (square == x) return mid;
        else if (square < x) start = mid + 1;
        else end = mid - 1;
    }
    return end;
}