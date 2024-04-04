bool isPerfectSquare(int num) {
    if (num == 0 || num == 1) return true;
    
    // Use binary search to narrow the square root
    int start = 1, end = num, mid = -1;
    long int square;
    while (start <= end) {
        mid = start + (end - start) / 2;

        square = (long int)mid * mid;

        if (square == num) return true;
        else if (square < num) start = mid + 1;
        else end = mid - 1;
    }
    return end * end == num;
}
