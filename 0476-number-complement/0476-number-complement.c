int findComplement(int num) {
    uint32_t k = 1;
    while (k <= num) k <<= 1;
    return ~num & (k - 1);
}