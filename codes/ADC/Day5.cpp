#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <fstream>

using namespace std;
typedef long long int lint;

int main() {
    ifstream file;
    file.open("/Users/vikaschaurasiya/Desktop/input_1.txt");
    if (file.fail()) {
        cerr << "Error : " << strerror(errno) << endl;
        return 1;
    }
    int num;
    vector <int> A;
    while (file >> num) {
        A.push_back(num);
    }
    int i = 0, steps = 0;
    while (i >= 0 && i < A.size()) {
        int skip = A[i];
        A[i] += 1;
        i += skip;
        steps += 1;
    }
    cout << steps << endl;
    return 0;
}
