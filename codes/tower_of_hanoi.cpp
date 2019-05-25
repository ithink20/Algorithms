#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>


using namespace std;

typedef long long int lint;

void tower_of_hanoi(int n, char source, char dest, char helper) {
    if (n == 0) {
        return;
    }
    tower_of_hanoi(n - 1, source, helper, dest);
    cout << "Move " << n << " disk from " << source << " to " << dest << endl;
    tower_of_hanoi(n - 1, helper, dest, source);
}

int main() {
    int N;
    cin >> N;
    tower_of_hanoi(N, 'A', 'C', 'B');
    return 0;
}
