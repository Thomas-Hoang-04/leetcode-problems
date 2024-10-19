char findKthBit(int n, int k) {
    int pos = k & -k;
    bool isInverted = ((k / pos) >> 1) & 1;
    bool isOneOrg = !(k & 1);
    return isInverted ? (isOneOrg ? '0' : '1') : (isOneOrg ? '1' : '0');
}