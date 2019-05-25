def main():
    A = [[0,0,0,2,6,0,7,0,1],
          [6,8,0,0,7,0,0,9,0],
          [1,9,0,0,0,4, 5,0,0],
          [8,2,0,1,0,0,0,4,0],
          [0,0,4,6,0,2,9,0,0],
          [0,5,0,0,0,3,0,2,8],
          [0,0,9,3,0,0,0,7,4],
          [0,4,0,0,5,0,0,3,6],
          [7,0,3,0,1,8,0,0,0]]
    if (solveSudoku(A)):
        display(A)
    else:
        print "can't be solved!"

def solveSudoku(A):
    l = [0, 0] #list for row & col in searchUnassigned.
    if (not searchUnassigned(A, l)):
        return True
    row = l[0]
    col = l[1]

    for digit in range(1, 10):
        if (is_safe(A, row, col, digit)):
            A[row][col] = digit
            # return if successful,
            if(solveSudoku(A)):
                return True
            A[row][col] = 0

    return False    #triggers backtracking

def searchUnassigned(A, l):
    for row in range(9):
        for col in range(9):
            if (A[row][col] == 0):
                l[0] = row
                l[1] = col
                return True
    return False

def is_safe(A, row, col, n):
    return not in_row(A, row, n) and not in_col(A, col, n) and not in_box(A, row - row % 3, col - col % 3, n)

def in_row(A, row, n):
    for col in range(9):
        if A[row][col] == n:
            return True
    return False

def in_col(A, col, n):
    for row in range(9):
        if A[row][col] == n:
            return True
    return False

def in_box(A, row, col, n):
    for i in range(3):
        for j in range(3):
            if A[i + row][j + col] == n:
                return True
    return False

def display(A):
    for row in range(9):
        for col in range(9):
            print A[row][col],
        print ('')

if __name__ == '__main__':
    main()