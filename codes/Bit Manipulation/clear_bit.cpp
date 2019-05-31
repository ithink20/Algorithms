int clearBit(int x, unsigned char postition) {
    int mask = 1 << postition;
    return x & ~mask;
}
