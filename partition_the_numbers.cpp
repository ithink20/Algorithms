// problem: https://www.codechef.com/problems/PRTITION

#include <stdio.h>
#include <vector>
#include <algorithm>

typedef long long int lint;

using namespace std;

int solve(int x, int N, int start_flag_value) {
  vector<int> A, B;
  lint sumA = 0, sumB = 0;
  int flag = start_flag_value;  // [0, 1] for A, [2, 3] for B
  for (int i = 1; i <= N; i++) {
    if (i == x) {
      continue;
    }
    if (flag == 0 || flag == 1) {
      A.push_back(i);
      sumA += i;
    } else {
      B.push_back(i);
      sumB += i;
    }
    flag = (flag + 1) % 4;
  }
  if (sumA < sumB) {
    swap(sumA, sumB);
    swap(A, B);
  }
  // sumA >= sumB now
  int sumDiff = sumA - sumB;
  if (sumDiff % 2 != 0) {
    return 0;
  }
  int foundSolution = (sumDiff == 0) ? 1 : 0;
  if (sumDiff != 0) {
    int halfDiff = sumDiff / 2;
    for (int i = 0; i < A.size(); i++) {
      if (A[i] > halfDiff) {
        int findNum = A[i] - halfDiff;
        vector<int>::iterator it = lower_bound(B.begin(), B.end(), findNum);
        if (it != B.end() && *it == findNum) {
          // found solution swap numbers
          *it = A[i];
          A[i] = findNum;
          foundSolution = 1;
          break;
        }
      }
    }
  }
  if (foundSolution == 0) {
    return 0;
  }
  sort(A.begin(), A.end());
  for (int i = 1; i <= N; i++) {
    if (i == x) {
      printf("2");
    } else if (binary_search(A.begin(), A.end(), i)) {
      printf("0");
    } else {
      printf("1");
    }
  }
  printf("\n");
  return 1;
}

int main() {
  int testCases;
  scanf("%d", &testCases);
  while (testCases--) {
    int x, N;
    scanf("%d%d", &x, &N);
    // solve(x, N, 0): assign first 2 numbers in first set, then assign pairs
    // solve(x, N, 1): assign first 1 number in first set, then assign pairs
    if (solve(x, N, 0) == 0 && solve(x, N, 1) == 0) {
      printf("impossible\n");
    }
  }
  return 0;
}
