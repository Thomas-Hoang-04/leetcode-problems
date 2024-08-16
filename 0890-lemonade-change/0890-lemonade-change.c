bool lemonadeChange(int* bills, int billsSize) {
    int f = 0, t = 0;

    while (billsSize--) {
        if (*bills == 5) f++;
        else if (*bills == 10) {
            if (f <= 0) return 0;
            f--;
            t++;
        } else {
            if (f > 0 && t > 0) {
                f--;
                t--;
            } else if (f >= 3) f -= 3;
            else return 0;
        }
        bills++;
    }

    return 1;
}