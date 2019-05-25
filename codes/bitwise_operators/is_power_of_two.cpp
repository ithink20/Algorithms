bool isPowerofTwo(unsigned int x) {
    return ((x & (x - 1)) == 0)
}
