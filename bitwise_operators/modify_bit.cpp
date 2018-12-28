int modifyBit(int x, unsigned char position, bool newstate) {
    int mask = 1 << position;
    int state = int(newstate);  //true = 1, false = 0
    return (x & ~mask) | (-state & mask);
}
