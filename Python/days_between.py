from datetime import date

def days(date1, date2):
    """
    Find absolute difference in days between dates
    """
    start = date(date1[0], date1[1], date1[2])
    end = date(date2[0], date2[1], date2[2])
    diff = end - start
    return abs(diff.days)

if __name__ == '__main__':
    print days((1982, 4, 19), (1982, 4, 22))
    print days((2014, 1, 1), (2014, 8, 27))
    print days((2014, 8, 27), (2014, 1, 1))
