int setBit(int x, unsigned char position) {
    int mask = 1 << position;
    return x | mask;
}
