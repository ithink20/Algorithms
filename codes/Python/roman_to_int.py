def main():
    roman = raw_input()
    total = 0
    i = 0
    while i < len(roman):
        s1 = value(roman[i])
        # print s1
        if (i + 1 < len(roman)):
            s2 = value(roman[i + 1])
            if (s1 >= s2):
                total += s1
            else:
                total = total + s2 - s1
                i += 1
        else:
            total += s1
            i += 1
        i += 1
    print total


def value(c):
    if c == 'I':
        return 1
    if c == 'V':
        return 5
    if c == 'X':
        return 10
    if c == 'L':
        return 50
    if c == 'C':
        return 100
    if c == 'D':
        return 500
    if c == 'M':
        return 1000
    return -1

if __name__ == '__main__':
    main()