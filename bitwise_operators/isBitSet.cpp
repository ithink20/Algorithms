bool isBitSet(int x, unsigned char position) {
    x >>= position;
    return (x & 1) != 0;
}
