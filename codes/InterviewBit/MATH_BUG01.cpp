#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <cmath>

using namespace std;
typedef long long int lint;

int isPrime(int A) {
    int upperLimit = (int)(sqrt(A));
    if (A > 1) {
        for (int i = 2; i <= upperLimit; i += 1) {
            if (A % i == 0) return 0;
        }
    } else {
        return 0;
    }
    return 1;
}


int main() {
    int N;
    cin >> N;
    cout << isPrime(N) << endl;
    return 0;
}
