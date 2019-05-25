# @author : vikaschaurasiya

s = raw_input()
A = map(int, s.split())

max_so_far, max_ending_here = 0, 0

for x in A[1:]:
    max_ending_here = max(x, max_ending_here + x)
    max_so_far = max(max_so_far, max_ending_here)
print max_so_far
